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

## 🛠️ Requirements & Setup on CachyOS

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

### 2. Setup
* Download and add the `slots.c` code in a folder like `/home/YOUR_USERNAME/slots/`
* Create an alias in .bashrc or .zshrc (Based on system): `alias slots='gcc /home/YOUR_USERNAME/slots/slots.c -o /tmp/slots && /tmp/slots'`

### 3. Enjoy Gambling

# EXTRA
### 📦 How to Compile Across Different Distributions
* **Because different Linux distributions use different package managers, use the appropriate installation command for your target machine before building:**


