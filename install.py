import archinstall
from archinstall import ask_for_a_timezone, ask_hostname, select_mirror_regions, GlobalMenu, select_harddrives, \
    get_password, select_disk_layout, has_uefi, ask_for_additional_users, ask_to_configure_network

passwords = get_password()

keyboard_layout = 'us'
mirror = select_mirror_regions()
sys_langauge = 'en_US'
sys_encoding = 'UTF-8'
hard_drives = select_harddrives()
disk_layout = select_disk_layout(block_devices=hard_drives, preset=None)
encrypt_disk = True if input('Do you want to encrypt the disk? [y/N] ') == 'y' else False
swap = True
bootloader = 'systemd-bootctl' if has_uefi() else 'grub-install'
hostname = ask_hostname()
users = ask_for_additional_users()
audio = 'pipewire'
kernels = ['linux-zen']
network = ask_to_configure_network(preset=None)
timezone = ask_for_a_timezone()
ntp = True


