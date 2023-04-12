{
    description = "NixOS configuration";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

        home-manager = {
            url = "github:nix-community/home-manager";
            inputs.nixpkgs.follows = "nixpkgs";
        };

        hyprland.url = "github:hyprwm/Hyprland";
    };

    services.xserver.displayManager.gdm = {
        enable = true;
        wayland = true;
    };

    services.xserver.displayManager.defaultSession = "hyprland";

    outputs = { self, nixpkgs, home-manager, hyprland }:
        let
            system = "x86_64-linux";
            pkgs = import nixpkgs {
                inherit system;
                config.allowUnfree = true;
            };
            lib = nixpkgs.lib;
        in {
            nixosConfigurations = {
                vm = lib.nixosSystem {
                    modules = [
                        (import ./hosts/vm.nix)
                        home-manager.nixosModules.home-manager
                        ({ pkgs, ... }: {
                            environment.systemPackages = with pkgs; [
                                (callPackage ./nixpkgs.nix {})
                            ];
                        })
                    ];
                };
            };
        };
}
