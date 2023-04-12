{ config, pkgs, hyprland, ... }:

{
  boot.loader.grub = {
    enable = true;
    version = 2;
    efiSupport = true;
  };

  boot.kernelPackages = pkgs.linuxPackages_latest;


  services.wayland.enable = true;
  imports = [
    hyperland.nixosModules.hyperland
  ];

  nixpkgs.config.allowUnfree = true;

  environment.systemPackages = with pkgs; [
    wget
    git
    vim
  ];

  users.users.brandon = {
    password = "changeme";
    isNormalUser = true;
    extraGroups = [ "wheel" ];
    shell = pkgs.zsh;
  };
}
