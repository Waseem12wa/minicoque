{ pkgs }: {
	deps = [
   pkgs.norminette
   pkgs.valgrind
   pkgs.wget
   pkgs.openssh
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