Teeworlds HunterN猎人杀
=====================
基于Teeworlds 0.6.5<br />
我只负责往屎山加屎 修BUG请提交代码qwq<br />

规则：每回合秘密抽选猎人，猎人对战平民，猎人双倍伤害，有瞬杀锤子和破片榴弹，活人看不到死人消息

比此前社区服开的Hunter有以下内容的差异：
-----------------------
## 更改或加入以下游戏内容：
更改：猎人榴弹满伤从26改为20(破片从20改14)<br />
更改：使ninja适配Hunter(猎ninja20伤,平民ninja13伤)<br />
更改：Ninja(忍者刀)生成时间从90s改70s(重生时间仍是90s)<br />
加入：开局平民文字提示<br />
加入：开局身份音效提示<br />
加入：指令if(从[InfectionDust](https://github.com/InfectionDust/teeworlds-infclassR/)移植)和"没有此命令"提示<br />
加入：whisper&converse悄悄话质量(有阴阳两隔检测)<br />
加入：回合结束显示猎人列表<br />
加入：还没完善的Funround<br />
加入：一堆没用的rcon命令<br />
更改：几乎完整的中文翻译<br />

## 加入了以下地图：
smallbomb、huntern5

如何构建? Building
--------------
你可以用CMake和[Bam](https://github.com/matricks/bam)构建.
详情参考[Teeworlds原版储存库](https://github.com/teeworlds/teeworlds)中的编译方法

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
