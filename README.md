# Pokémon Maragda - Traducció al Català

Aquesta és una traducció al català de Pokémon Emerald (pokeemerald decompilation).

## Compilació

### Requisits previs

#### macOS

1. Instal·la les Xcode Command Line Tools:

```bash
xcode-select --install
```

2. Instal·la [Homebrew](https://brew.sh/) i libpng:

```bash
brew install libpng
```

3. Instal·la devkitARM:

```bash
# Descarrega el paquet devkitpro-pacman-installer.pkg des de:
# https://github.com/devkitPro/pacman/releases

sudo dkp-pacman -Sy
sudo dkp-pacman -S gba-dev
sudo dkp-pacman -S devkitarm-rules

export DEVKITPRO=/opt/devkitpro
echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
export DEVKITARM=$DEVKITPRO/devkitARM
echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc
```

#### Linux (Debian/Ubuntu)

```bash
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev
```

#### Linux (Arch)

```bash
sudo pacman -S base-devel arm-none-eabi-binutils arm-none-eabi-newlib git libpng
```

#### Windows

Instal·la [Windows Subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) (WSL1 recomanat) i segueix les instruccions de Linux.

### Compilar la ROM

1. Clona el repositori i agbcc:

```bash
git clone https://github.com/project-arktosmos/pokemon-maragda
git clone https://github.com/pret/agbcc
cd agbcc
./build.sh
./install.sh ../pokemon-maragda
cd ../pokemon-maragda
```

2. Compila la ROM:

```bash
make
```

La ROM resultant serà `pokeemerald.gba`.

Per compilar més ràpid amb múltiples nuclis:

```bash
make -j$(nproc)
```

A macOS, utilitza:

```bash
make -j$(sysctl -n hw.ncpu)
```

### Comparar amb la ROM original

Per verificar que la ROM és idèntica a l'original:

```bash
make compare
```

Si coincideix, veuràs: `pokeemerald.gba: OK`

## ROM generada

- **pokeemerald.gba** `sha1: f3ae088181bf583e55daf962a92bb46f4f1d07b7`

## Eines útils

- [porymap](https://github.com/huderlem/porymap) - per veure i editar mapes
- [poryscript](https://github.com/huderlem/poryscript) - per fer scripts
- [Tilemap Studio](https://github.com/Rangi42/tilemap-studio) - per veure i editar tilemaps

## Més informació

Per a més projectes de pret, visita [pret.github.io](https://pret.github.io/).

---

*Basat en el projecte [pokeemerald](https://github.com/pret/pokeemerald) de pret.*
