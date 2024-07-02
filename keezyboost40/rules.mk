# MCU name

# Bootloader selection

PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS!
VIA_ENABLE = yes
# Build Options
#   change yes to no to disable
#
EXTRAKEY_ENABLE = yes       # Audio control and System controls
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = yes         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi
SRC += myimage.qgf.c

