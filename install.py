import archinstall
from archinstall import ask_for_a_timezone, ask_hostname, select_mirror_regions, GlobalMenu, select_harddrives, \
    get_password, select_disk_layout, has_uefi, ask_for_additional_users, ask_to_configure_network, \
    NetworkConfigurationHandler

KEYBOARD_LAYOUT = 'us'
LOCALE = 'en_US'
BOOTLOADER = 'systemd-bootctl' if has_uefi() else 'grub-install'
KERNELS = ['linux-zen']

ROOT_PASSWORD = get_password('Enter root password')
MIRROR = select_mirror_regions()
HARD_DRIVES = select_harddrives()
DISK_LAYOUT = select_disk_layout(block_devices=HARD_DRIVES, preset=None)
ENCRYPT_DISK = True if input('Do you want to encrypt the disk? [y/N] ') == 'y' else False
HOSTNAME = ask_hostname()
USERS = ask_for_additional_users()
NETWORK = ask_to_configure_network(preset=None)
TIMEZONE = ask_for_a_timezone()

mode = archinstall.GPT
if archinstall.has_uefi() is False:
    mode = archinstall.MBR

for drive in HARD_DRIVES:
    if DISK_LAYOUT.get(drive.path):
        with archinstall.Filesystem(drive, mode) as fs:
            fs.load_layout(DISK_LAYOUT[drive.path])


with archinstall.Installer('/mnt', kernels=KERNELS) as installation:
    installation.set_keyboard_language(KEYBOARD_LAYOUT)
    installation.set_locale(LOCALE)
    installation.set_timezone(TIMEZONE)
    archinstall.Application(installation, 'pipewire').install()
    installation.activate_time_syncronization()
    installation.setup_swap()
    installation.add_bootloader(BOOTLOADER)
    installation.set_hostname(HOSTNAME)
    installation.create_users(USERS)
    installation.set_mirrors(MIRROR)

    NetworkConfigurationHandler(NETWORK).config_installer(installation)
    installation.user_set_pw('root', ROOT_PASSWORD)
    installation.genfstab()
