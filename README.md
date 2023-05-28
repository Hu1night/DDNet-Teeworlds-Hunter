Teeworlds HunterN猎人杀
=====================
基于Hunter模式(Teeworlds 0.6.5)<br />
我只负责往屎山加屎 修BUG请提交代码qwq<br />

模式规则：一命DM死斗但每回合秘密抽选猎人，其他人(即平民)对战猎人，猎人双倍伤害，有瞬杀锤子(平民无锤)和破片榴弹(对自己无伤)，活人看不到死人消息，猎人死亡通知其他猎人，开局仅知道自己身份

与原Hunter模式的区别：
-----------------------
更改：猎人榴弹满伤从26改为24(破片从20改18)<br />
更改：使ninja适配Hunter(猎ninja20伤,平民ninja13伤)<br />
更改：Ninja(忍者刀)生成时间从90s改70s(重生时间仍是90s)<br />
更改：每次捡起ninja会额外给予1心 可以超出血量上限 可以叠加<br />
加入：开局平民文字提示<br />
加入：开局身份音效提示<br />
加入：指令if(从[InfectionDust](https://github.com/InfectionDust/teeworlds-infclassR/)移植)和"没有此命令"提示<br />
加入：whisper&converse悄悄话指令(有阴阳两隔检测)<br />
加入：回合结束显示猎人列表<br />
加入：还没完善的Funround<br />
加入：一堆没用的rcon命令<br />
更改：几乎完整的中文翻译<br />

加入了以下地图：
smallbomb、huntern5、huntern_doomsday、huntern_qianye

如何使用
--------------
1.下载最新的[Release](https://github.com/Hu1night/DDNet-Teeworlds-Hunter/releases)或开发版构建([项目Action](https://github.com/Hu1night/DDNet-Teeworlds-Hunter/actions/workflows/build.yaml)),也可从源码构建<br />
2.开服前根据需求更改autoexec.cfg(如服务器名字,F2控制台密码,投票等)<br />
3.运行hunter_srv.exe(Windows系统)或hunter_srv(Linux系统)开服

在Ubuntu上使用bam构建
--------------
1.确保bam及相关组件已安装<br />
```sudo apt update
sudo apt install build-essential bam python3
```
2.到本地项目编译<br />
```bam server_release
```

在Ubuntu上使用CMake构建
--------------
1.确保CMake及相关组件已安装<br />
```sudo apt update
sudo apt install build-essential cmake python3
```
2.到本地项目编译<br />
```cmake .
make -j16
```

在其他系统上的构建请参阅[Teeworlds储存库](https://github.com/teeworlds/teeworlds)
--------------

以下是原作者的readme
-------------

Copyright (c) 2012 Magnus Auvinen


This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.


Please visit http://www.teeworlds.com for up-to-date information about 
the game, including new versions, custom maps and much more.

Hunter Modifications by bluelightzero.
If you find any bugs please report to:

	http://github.com/bluelightzero/teeworlds-hunter
	
Modifications are marked As:

	/* Hunter start */

	==========
	== Code ==
	==========

	/* Hunter end */

Or:

	== Code == // Hunter
