{
  description = "snake simulator I wrote in high school";

  inputs = {
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (
      system:
        with nixpkgs.lib;
        with nixpkgs.legacyPackages.${system}; {
          packages.default = stdenv.mkDerivation rec {
            pname = "snake-simulator";
            version = "0.1";
            nativeBuildInputs = [cmake];
            buildInputs = [ncurses6 boost];
            src = ./.;
            installPhase = ''
              mkdir -p $out/bin
              cp snake $out/bin/${pname}
            '';
          };
        }
    );
}
