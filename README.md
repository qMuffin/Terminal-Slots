# 🎰 Terminal Slots Game

A lightweight, high-performance terminal slot machine game written in pure C. It features colorized ANSI outputs, frame-by-frame text rendering for a spinning wheel animation, and multi-byte UTF-8 emoji parsing for a modern CLI experience.

## ✨ Features
* **Live Reel Animation:** Uses explicit `usleep` timing delays and ANSI terminal escape sequences (`\033[3A\r`) to overwrite lines, creating a smooth visual spin effect directly inside your terminal window.
* **Smart Color Matching:** Automatically parses multi-byte UTF-8 emoji sequences to apply matching color themes (e.g., Yellow borders for 👑, Red for 🍒).
* **Dynamic Winnings:** 
  * 👑 **Jackpot:** 3 Crowns yields **10x** your bet.
  * 🍒🍋🍊🍉 **Three of a Kind:** Yields **5x** your bet.
  * 👥 **Pair:** Any 2 matching symbols yields **2x** your bet.

---

* **Everything was tested on my machine running ArchLinux with CachyOS distro and KDE Plasma.**
* **The terminal used was Ghostty.**

---

## 🛠️ Requirements & Setup

Setting up the required developer tools takes only a few seconds.

### 1. Install Dependencies
* Open your terminal and install the `base-devel` package group (which includes `gcc`, `make`, and `glibc` needed for compiling C code):

* **Arch Linux / CachyOS:** 
```bash 
sudo pacman -S base-devel
```

* **Ubuntu / Debian / Mint:** 
```bash 
sudo apt update && sudo apt install build-essential
```

* **Fedora / RHEL / CentOS:** 
```bash
sudo dnf groupinstall "Development Tools"
```

* **openSUSE:** 
```bash
sudo zypper install --type pattern devel_basis
```
---

### 2. Setup
* **Create the directory and file:**
```bash
mkdir -p ~/slots
nano ~/slots/slots.c
```
(Paste the C code inside, press `Ctrl+O` then `Enter` to save, and `Ctrl+X` to exit)

* **Create an alias in your configuration file for Bash (Ubuntu, Fedora, Mint, default CachyOS):**

```bash
echo "alias slots='gcc /home/\$USER/slots/slots.c -o /tmp/slots && /tmp/slots'" >> ~/.bashrc
source ~/.bashrc
```

* **For Zsh (Mac, or custom Zsh setups):**

```bash
echo "alias slots='gcc /home/\$USER/slots/slots.c -o /tmp/slots && /tmp/slots'" >> ~/.zshrc
source ~/.zshrc
```
---

### 3. Enjoy Gambling
* **Now, simply open any terminal window and type:**
```bash
slots
```



