# DM-Orin载板的DTB修改教程

**示例环境：**

**主机为 Ubuntu 20.04**

**以下Jetpack 5.1.3为例，在主机修改并编译kernel及dtb文件。**

# **准备工作**

- **查看Jetpack 5.1.3：https://developer.nvidia.com/embedded/jetpack-sdk-513**
- **找到Jetlinux 35.5.0：https://developer.nvidia.com/embedded/jetson-linux-r3550**
- **下载源码：[Driver Package (BSP) Sources](https://developer.nvidia.com/downloads/embedded/l4t/r35_release_v5.0/sources/public_sources.tbz2)**
- **下载编译工具链：[Bootlin Toolchain gcc 9.3](https://developer.nvidia.com/embedded/jetson-linux/bootlin-toolchain-gcc-93)**

官方的修改流程在

[Jetson Linux Developer Guide (online version)](https://docs.nvidia.com/jetson/archives/r35.5.0/DeveloperGuide/index.html)

这里面找到 • [Jetson Module Adaptation and Bring-Up](https://docs.nvidia.com/jetson/archives/r35.5.0/DeveloperGuide/HR/JetsonModuleAdaptationAndBringUp.html) » [Jetson Orin NX and Nano Series](https://docs.nvidia.com/jetson/archives/r35.5.0/DeveloperGuide/HR/JetsonModuleAdaptationAndBringUp/JetsonOrinNxNanoSeries.html)

# 配置编译环境

解压aarch64--glibc--stable-final.tar.gz到指定文件夹，这里以`$HOME/nv_src`举例

可以得到以下的文件结构

![1](https://gitee.com/kit-miao/damiao/raw/master/%E6%8E%A7%E5%88%B6%E6%9D%BF/ORIN%20%E8%BD%BD%E6%9D%BF/image/%E6%96%87%E4%BB%B6%E7%BB%93%E6%9E%84.png)

将以下命令写入你的`~/.bashrc`或者`~/.zshrc` ,以配置环境变量(注意修改为你自己解压的路径)

```bash
export CROSS_COMPILE_AARCH64_PATH=$HOME/nv_src/aarch64--glibc--stable-final
export CROSS_COMPILE=$HOME/nv_src/aarch64--glibc--stable-final/bin/aarch64-buildroot-linux-gnu-
```

# 解压源码并编译

接下来可以解压源码，打开压缩包文件，解压`kernel_src`

![1](https://gitee.com/kit-miao/damiao/raw/master/%E6%8E%A7%E5%88%B6%E6%9D%BF/ORIN%20%E8%BD%BD%E6%9D%BF/image/%E8%A7%A3%E5%8E%8B%E6%BA%90%E7%A0%81.png)

然后可以执行一次编译测试一下,第一波会时间比较久（如果你知道在做啥，可以修改对应脚本，只编译dtbs相关）

```bash
cd kernel_src
mkdir -p kernel_out
./nvbuild.sh -o $PWD/kernel_out
```

# 修改DTB源码并测试

接下来可以尝试修改对应的dtb源码文件。Orin系列对应的dtb源码均在`kernel_src/hardware/nvidia/platform/t23x/p3768/kernel-dts/` 路径下。

为了修改USB3.0和串口的配置，可以直接修改 `cvb/tegra234-p3768-0000-a0.dtsi` 这一文件：

```bash
	serial@3100000 {/* UARTA, for 40 pin header */
		status = "okay";
	};

	/* 增加下面这部分开启串口1 */
	serial@3110000 {/* Enable UART1 */
		status = "okay";
	};
	
	/* ......  */
	
	/* 找到这部分，并按照下面的修改，增加usb2-2和usb3-2，用于开启额外的USB3.0 */
	xusb_padctl: xusb_padctl@3520000 {
		status = "okay";
		pads {
			usb2 {
				lanes {
					usb2-0 {
						nvidia,function = "xusb";
						status = "okay";
					};
					usb2-1 {
						nvidia,function = "xusb";
						status = "okay";
					};
					usb2-2 {
						nvidia,function = "xusb";
						status = "okay";
					};
				};
			};
			usb3 {
				lanes {
					usb3-0 {
						nvidia,function = "xusb";
						status = "okay";
					};
					usb3-1 {
						nvidia,function = "xusb";
						status = "okay";
					};
					usb3-2 {
						nvidia,function = "xusb";
						status = "okay";
					};
				};
			};
		};

		ports {
			usb2-0 {/* Goes to recovery port */
				mode = "otg";
				status = "okay";
				vbus-supply = <&p3768_vdd_5v_sys>;
				usb-role-switch;
				port {
					typec_p0: endpoint {
						remote-endpoint = <&fusb_p0>;
					};
				};
			};
			usb2-1 {/* Goes to hub */
				mode = "host";
				vbus-supply = <&p3768_vdd_av10_hub>;
				status = "okay";
			};
			usb2-2 {/* Goes to M2.E */
				mode = "host";
				vbus-supply = <&p3768_vdd_5v_sys>;
				status = "okay";
			};
			usb3-0 {/* Goes to hub */
				nvidia,usb2-companion = <1>;
				status = "okay";
			};
			usb3-1 {/* Goes to J5 */
				nvidia,usb2-companion = <0>;
				status = "okay";
			};
			usb3-2 {/* Goes to J5 */
				nvidia,usb2-companion = <2>;
				status = "okay";
			};
		};
	};

	tegra_xudc: xudc@3550000 {
		status = "okay";
		phys = <&{/xusb_padctl@3520000/pads/usb2/lanes/usb2-0}>,
			<&{/xusb_padctl@3520000/pads/usb3/lanes/usb3-1}>;
		phy-names = "usb2-0", "usb3-1";
		nvidia,xusb-padctl = <&xusb_padctl>;
	};

	tegra_xhci: xhci@3610000 {
		status = "okay";
		phys = <&{/xusb_padctl@3520000/pads/usb2/lanes/usb2-0}>,
			<&{/xusb_padctl@3520000/pads/usb2/lanes/usb2-1}>,
			<&{/xusb_padctl@3520000/pads/usb2/lanes/usb2-2}>,
			<&{/xusb_padctl@3520000/pads/usb3/lanes/usb3-0}>,
			<&{/xusb_padctl@3520000/pads/usb3/lanes/usb3-1}>,
			<&{/xusb_padctl@3520000/pads/usb3/lanes/usb3-2}>;
		phy-names = "usb2-0", "usb2-1", "usb2-2", "usb3-0", "usb3-1", "usb3-2";
		nvidia,xusb-padctl = <&xusb_padctl>;
	};
```

修改完成后，执行上面的脚本编译

```bash
cd kernel_src
./nvbuild.sh -o $PWD/kernel_out

# 编译好的dtb文件会在 kernel_out/arch/arm64/boot/dts/nvidia 路径下
# 如果你不确定你需要哪个，最简单的办法是打开你的orin，看一下/boot/dtb下面的文件
```

找到对应的dtb，就可以直接替换到orin上`/boot`和`/boot/dtb`下面的文件，重启生效

# 附：

1. P3767-0000这些神秘代码都是什么意思？

其中P3768-0000，就是你的载板，可以根据这些名字，找到对应的dts和dtsi文件，根据你的需求进行修改。

[Quick Start — NVIDIA Jetson Linux Developer Guide 1 documentation](https://docs.nvidia.com/jetson/archives/r35.5.0/DeveloperGuide/IN/QuickStart.html)

| Module                                 | Module Type                                 | Carrier Board                                         | Configuration           | Configuration Notes                                          |
| -------------------------------------- | ------------------------------------------- | ----------------------------------------------------- | ----------------------- | ------------------------------------------------------------ |
| Jetson Orin NX 16GB-DRAM (P3767-0000)  | Production                                  | Jetson Orin Nano reference carrier board (P3768-0000) | jetson-orin-nano-devkit | Flashes QSPI-NOR and USB/NVMe drive (only supported via l4t_initrd_flash.sh) |
| Jetson Orin NX 8GB-DRAM (P3767-0001)   | Production                                  | Jetson Orin Nano reference carrier board (P3768-0000) | jetson-orin-nano-devkit | Flashes QSPI-NOR and USB/NVMe drive (only supported via l4t_initrd_flash.sh) |
| Jetson Orin Nano 8GB-DRAM (P3767-0003) | Production                                  | Jetson Orin Nano reference carrier board (P3768-0000) | jetson-orin-nano-devkit | Flashes QSPI-NOR and USB/NVMe drive (only supported via l4t_initrd_flash.sh) |
| Jetson Orin Nano 4GB-DRAM (P3767-0004) | Production                                  | Jetson Orin Nano reference carrier board (P3768-0000) | jetson-orin-nano-devkit | Flashes QSPI-NOR and USB/NVMe drive (only supported via l4t_initrd_flash.sh) |
| Jetson Orin Nano 8GB-DRAM (P3767-0005) | Development（就是官方版开发套件，带sd卡的） | Jetson Orin Nano reference carrier board (P3768-0000) | jetson-orin-nano-devkit | Flashes QSPI-NOR and microSD Card/USB/NVMe drive (only supported via l4t_initrd_flash.sh) |























