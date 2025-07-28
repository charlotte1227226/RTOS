# FreeRTOS 下載

1. **先把整個 FreeRTOS Repo clone 下來**（只要做一次）：

   ```bash
   git clone https://github.com/FreeRTOS/FreeRTOS.git --recurse-submodules
   ```

2. **選擇你要編譯的範例目錄**
   Repository 裡的範例都放在：

   ```
   FreeRTOS/
     FreeRTOS/
       Demo/
         <平台1>/
           GCC_Makefile/
         <平台2>/
           GCC_Makefile/
         …
     FreeRTOS-Plus/
       Demo/
         <Plus 元件範例>/
           GCC_Makefile/
   ```

   例如你想跑 STM32F407 Discovery 的範例，就進：

   ```bash
   cd FreeRTOS/FreeRTOS/Demo/CORTEX_M4F_STM32F407_DISCOVERY/GCC_Makefile
   ```

3. **執行 `make`**

   ```bash
   make
   ```

   這會自動呼叫 `arm-none-eabi-gcc`、`objcopy` 等，編出 `.elf`、`.bin`（或 hex）檔。

4. **檢查輸出**

   * 通常會在同一個資料夾看到 `main.elf`、`main.bin`、`main.map`。
   * 用你慣用的燒錄工具（OpenOCD、ST‑Link、J‑Link…）把 bin/elf 燒到目標板子。

---

### 小提醒

* **GCC\_Makefile** 才有 `make` 目標；其他像 IAR／Keil 的專案目錄下會是 `.eww`、`.uvproj` 等，你可以略過。
* 如果你要做 Pi5 裸機（bare‑metal）版，就要找社群維護的 Pi port，目錄結構會不同，但原理一樣──進到對應的 Makefile 目錄下 `make`。
* 作為開發主機（host），Raspberry Pi 5 上安裝好 `gcc-arm-none-eabi`、`make`、`git` 後，就能在 Pi5 上直接編任何官方 Demo。

照這樣操作，就能把你想要的範例編譯出來啦！
