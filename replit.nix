{ pkgs }: {
	deps = [
   pkgs.killall
   pkgs.sptk
		pkgs.readline
   	pkgs.bash
		pkgs.clang
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}