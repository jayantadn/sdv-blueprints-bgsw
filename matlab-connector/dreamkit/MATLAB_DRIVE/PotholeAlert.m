%% parameter
% Matches Python pothole_hazard_logic.py default threshold of -5/+5
STEERING_THRESHOLD = Simulink.Parameter;
STEERING_THRESHOLD.Value = 5;

%% model name
model = "PotholeAlert";

%% create model
new_system(model)
open_system(model)

%% add test signal sources (replacing In1 blocks for testing)
% Sine wave: 25*sin(0.5*t), period = 4*pi = 12.57s (freq=0.5 rad/s)
% Zero crossings at t = 0, 6.28, 12.57s
% RIGHT peak (steering = +25) at t = 3.14s (positive sine)
% LEFT peak (steering = -25) at t = 9.42s (negative sine)

% Case 1: Right hazard - pulse at t=2s to t=4s (covers RIGHT peak at t=3.14s where steering=+25)
% Expected: HAZARD ON (right pothole + turning right)
add_block("simulink/Sources/Pulse Generator", model + "/pothole_right")
set_param(model + "/pothole_right","Period","20","PulseWidth","10","PhaseDelay","2","Amplitude","1")

% Case 2: Center lane - pulse at t=5.5s to t=7s (covers 2nd zero crossing at t=6.28s where steering=0)
% Expected: NO HAZARD (center lanes ignored per Python logic - zones 2,5,8 not monitored)
add_block("simulink/Sources/Pulse Generator", model + "/pothole_center")
set_param(model + "/pothole_center","Period","20","PulseWidth","7.5","PhaseDelay","5.5","Amplitude","1")

% Case 3: Left hazard - pulse at t=8.5s to t=10.5s (covers LEFT peak at t=9.42s where steering=-25)
% Expected: HAZARD ON (left pothole + turning left)
add_block("simulink/Sources/Pulse Generator", model + "/pothole_left")
set_param(model + "/pothole_left","Period","20","PulseWidth","10","PhaseDelay","8.5","Amplitude","1")

% Steering angle - sine wave sweeping left and right like a charm
add_block("simulink/Sources/Sine Wave", model + "/steering_angle")
set_param(model + "/steering_angle","Amplitude","25","Frequency","0.5","SampleTime","0")

%% add output
add_block("simulink/Sinks/Out1", model + "/hazard_signal")

%% steering compare
add_block("simulink/Logic and Bit Operations/Compare To Constant", model + "/steer_left")
set_param(model + "/steer_left","const","-STEERING_THRESHOLD","relop","<")

add_block("simulink/Logic and Bit Operations/Compare To Constant", model + "/steer_right")
set_param(model + "/steer_right","const","STEERING_THRESHOLD","relop",">")

%% AND blocks
add_block("simulink/Logic and Bit Operations/Logical Operator", model + "/and_left")
set_param(model + "/and_left","Operator","AND")

add_block("simulink/Logic and Bit Operations/Logical Operator", model + "/and_right")
set_param(model + "/and_right","Operator","AND")

%% OR (only left and right lanes trigger hazard)
add_block("simulink/Logic and Bit Operations/Logical Operator", model + "/or")
set_param(model + "/or","Operator","OR","Inputs","2")

%% connections
add_line(model,"steering_angle/1","steer_left/1")
add_line(model,"steering_angle/1","steer_right/1")

add_line(model,"pothole_left/1","and_left/1")
add_line(model,"steer_left/1","and_left/2")

add_line(model,"pothole_right/1","and_right/1")
add_line(model,"steer_right/1","and_right/2")

% Connect only left and right to OR (center lanes ignored per Python logic)
add_line(model,"and_left/1","or/1")
add_line(model,"and_right/1","or/2")

add_line(model,"or/1","hazard_signal/1")

%% log all signals

add_block("simulink/Sinks/To Workspace", model + "/log_pothole_left")
set_param(model + "/log_pothole_left","VariableName","pothole_left_out")
add_line(model,"pothole_left/1","log_pothole_left/1")

add_block("simulink/Sinks/To Workspace", model + "/log_pothole_center")
set_param(model + "/log_pothole_center","VariableName","pothole_center_out")
add_line(model,"pothole_center/1","log_pothole_center/1")

add_block("simulink/Sinks/To Workspace", model + "/log_pothole_right")
set_param(model + "/log_pothole_right","VariableName","pothole_right_out")
add_line(model,"pothole_right/1","log_pothole_right/1")

add_block("simulink/Sinks/To Workspace", model + "/log_steering")
set_param(model + "/log_steering","VariableName","steering_out")
add_line(model,"steering_angle/1","log_steering/1")

add_block("simulink/Sinks/To Workspace", model + "/hazard_log")
set_param(model + "/hazard_log","VariableName","hazard_out")
add_line(model,"or/1","hazard_log/1")

%% arrange full model
Simulink.BlockDiagram.arrangeSystem(model)

%% save
save_system(model)

%% run simulation
set_param(model,"StopTime","12")
simOut = sim(model);

%% plot timing diagram
pothole_left_out = simOut.pothole_left_out;
pothole_center_out = simOut.pothole_center_out;
pothole_right_out = simOut.pothole_right_out;
steering_out = simOut.steering_out;
hazard_out = simOut.hazard_out;

figure

subplot(5,1,1)
plot(pothole_left_out.Time, pothole_left_out.Data, 'b', 'LineWidth', 1.5)
ylabel("Pothole Left")
xlim([0 12])
ylim([-0.5 1.5])
grid on
title("Timing Diagram - Hazard Logic (Python-aligned): Left+Right Only")

subplot(5,1,2)
plot(pothole_center_out.Time, pothole_center_out.Data, 'g', 'LineWidth', 1.5)
ylabel("Pothole Center")
xlim([0 12])
ylim([-0.5 1.5])
grid on

subplot(5,1,3)
plot(pothole_right_out.Time, pothole_right_out.Data, 'm', 'LineWidth', 1.5)
ylabel("Pothole Right")
xlim([0 12])
ylim([-0.5 1.5])
grid on

subplot(5,1,4)
plot(steering_out.Time, steering_out.Data, 'Color', [1 0.5 0], 'LineWidth', 1.5)
ylabel("Steering Angle")
xlim([0 12])
yline(-5, '--k', 'Left Threshold (-5°)')
yline(5, '--k', 'Right Threshold (+5°)')
grid on

subplot(5,1,5)
plot(hazard_out.Time, hazard_out.Data, 'r', 'LineWidth', 2)
ylabel("Hazard Signal")
xlabel("Time (s)")
xlim([0 12])
ylim([-0.5 1.5])
grid on