target.connection.close(board.Name);
target.remove([toolchain, targetConnection, board], 'IncludeAssociations', true);
clear ans board targetConnection toolchain cfg;