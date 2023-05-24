# SixTerms
    UE Plugins —— Sensitive string filtering/ UE 插件 字符串敏感词过滤替换*
## Function and Features / 功能与特点
  * Import UeTable,custom case string rows. / 导入UE表格,自定义敏感词行
  * Async Init This SubSystem for AnyThread. / 异步初始化该子系统 通过 AnyThread线程（这个异步任务完成执行线后面不要写游戏逻辑）
  * Async CheckString for GameTherad. / 异步检测字符串 通过 GameTherad （游戏线程异步，词汇行多了任然可能卡住游戏线程。但是我不知道多少会卡，目前我只测了1.8w行）
  * Custom alternative sting,default \*. / 可自定义替换字符，默认为 \*

## How to use / 如何使用
in UE or Download this to your project/Plugins   /在UE商城中免费获取，或下载这个文件到你的项目/Plugins 文件夹下
  1. Use Function AsyncSetTable_SixTerms set case string rows / 使用函数 AsyncSetTable_SixTerms 初始化查询表行
  2. Use Function AsyncCheckString_SixTerm check and replace string/ 使用函数 AsyncCheckString_SixTerm 过滤替换字符串
  3. Use Function SetScapegoat_SixTerm set alternative sting / 使用函数 SetScapegoat_SixTerm 可设置替换字符 

## 其他
* 内置了一个1.8w行的中文敏感字符串表 表名称为[DT_SixTerm]
* AsyncSetTable_SixTerms parameter Table struct must be SixTermStruct / AsyncSetTable_SixTerms 函数的Table参数必须是结构体为SixTermStruct 的表
* all function in namepace [StringTool] / 所有函数均位于 [StringTool] 命名空间
* Do not call the plugin at the beginning of the game. The delay should be more than 3s / 不要在游戏开始时就调用该插件应当延时3s以上(因为子系统还没有启动完成)