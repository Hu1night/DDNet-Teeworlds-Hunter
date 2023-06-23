Teeworlds HunterN猎人杀
=====================
基于Hunter模式(Teeworlds 0.6.5)<br />
我只负责往屎山加屎 修BUG请提交代码qwq<br />

模式规则：<br />
1.每回合都会秘密随机选择猎人。猎人必须消灭所有平民。<br />
2.猎人造成双倍伤害，有一把瞬杀锤和碎片榴弹，而平民没有锤子，只能使用常规武器。<br />
3.活着的玩家看不到死去玩家的信息。<br />
4.如果猎人死亡，将通知其他猎人。<br />
5.在游戏开始时，玩家只知道自己的身份。

Rules:<br />
1.Each round will secretly randomly select Hunter(s). Hunter(s) must eliminate all the Civilians.<br />
2.The Hunter deals double damage and has an instant-kill hammer and fragmentation grenades, while Civilians have no hammer and can only use regular weapons.<br />
3.The living players cannot see messages from dead players.<br />
4.If the Hunter dies, the other Hunters will be notified.<br />
5.At the beginning of the game, players only know their own identity.

与原Hunter模式的区别：
-----------------------
更改：猎人榴弹满伤从26改为24(破片从20改18)<br />
更改：使ninja适配Hunter(猎ninja20伤,平民ninja13伤)<br />
更改：Ninja(忍者刀)生成时间从90s改70s(重生时间仍是90s)<br />
更改：每次捡起ninja会额外给予1心 可以超出血量上限 可以叠加<br />
加入：开局平民文字提示<br />
加入：开局身份音效提示<br />
加入：指令if和"没有此命令"提示<br />
加入：whisper&converse悄悄话指令(有阴阳两隔检测)<br />
加入：回合结束显示猎人列表<br />
加入：还没完善的Funround<br />
加入：一堆没用的rcon命令<br />
更改：几乎完整的中文翻译<br />

加入了以下地图(按时间排序 作者按贡献排序)：
smallbomb、huntern5(by Hu1night)、huntern_doomsday(by 火锅Dio)、huntern_qianye(by Lazyfox & Hu1night)

如何使用
--------------
1.下载最新的[Release](https://github.com/Hu1night/DDNet-Teeworlds-Hunter/releases)或开发版构建(登录Github并在[项目Action](https://github.com/Hu1night/DDNet-Teeworlds-Hunter/actions/workflows/build.yaml)下载),也可从源码构建<br />
2.开服前根据需求更改autoexec.cfg(如服务器名字,F2控制台密码,投票等)<br />
3.运行hunter_srv.exe(Windows系统)或hunter_srv(Linux系统)开服

在Ubuntu上使用bam构建
--------------
1.确保bam及相关组件已安装<br />
```
sudo apt update
sudo apt install build-essential bam python3
```
2.到本地项目编译<br />
```
bam server_release
```

在Ubuntu上使用CMake构建
--------------
1.确保CMake及相关组件已安装<br />
```
sudo apt update
sudo apt install build-essential cmake python3
```
2.到本地项目编译<br />
```
cmake .
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
