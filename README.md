# C++ 竞赛模板库

这是一个为算法竞赛准备的 C++ 模板库，包含了经过实战检验的常用算法与数据结构实现。所有代码均采用现代 C++ 特性，追求简洁高效。

## 目录结构

### 数据结构 `/DataStructure`
- 线性基 
  - 基础版本 `Basis.cpp`
  - 完整版本 `BasisAll.cpp`
- 并查集
  - 基础版本 `DSU.cpp`
  - 带回滚功能 `DSURollback.cpp`
- 分数类 `Frac.cpp`
- 树状数组 `Fenwick.cpp`
- 线段树
  - 基础版本 `SegementTree.cpp`
  - 懒标记版本 `LazySegmentTree.cpp`
- Splay树 `Splay.cpp`
- LCT (Link Cut Tree) `LCT.cpp`
- RMQ (区间最值查询) `RMQ.cpp`

### 图论算法 `/Graph`
- 基础图论 `Graph.cpp`
- 网络流
  - 整数流 `FlowInt.cpp`
  - 浮点流 `FlowDouble.cpp`
  - 最大流 `MaxFlow.cpp`
  - 最小费用最大流
    - 可行流 `MCFGraphFeasibleFlow.cpp`
    - 最大流 `MCFGraphMaxFlow.cpp`
- 强连通分量 `SCC.cpp`
- 边双连通分量 `EBCC.cpp`
- 树链剖分 `HLD.cpp`
- 2-SAT问题 `TwoSat.cpp`
- 最大匹配 `MaxAssignment.cpp`

### 字符串算法 `/String`
- AC自动机
  - 基础版本 `AC.cpp`
  - 增强版本 `AhoCorasick.cpp`
- 后缀数组 `SuffixArray.cpp`
- 后缀自动机 `SAM.cpp`
- 回文自动机 `PAM.cpp`
- Manacher算法 `Manacher.cpp`
- Z函数 `ZFunction.cpp`

### 数学 `/Math`
- 基础数学 `Math.cpp`
- 数论
  - 素数筛法 `Sieve.cpp`
  - 欧拉函数 `Phi.cpp`
  - 扩展欧几里得 `Exgcd.cpp`
  - Miller-Rabin素性测试与Pollard-Rho因数分解 `Miller-RabinAndPollard-Rho.cpp`
  - 莫比乌斯函数求和 `SumMu.cpp`
- 组合数学
  - 组合数计算 `Comb.cpp`
  - 二项式系数 `Binominal.cpp`
- 多项式
  - 模意义下多项式 `PolyMInt.cpp`
  - 整数域多项式 `PloyZ.cpp`
- 数值类型
  - 模意义下整数
    - 基础版本 `MInt.cpp`
    - 增强版本 `ModInt.cpp`
  - 大整数 `BigInt.cpp`
- 计算几何
  - 基础几何 `Geometry.cpp`
  - 凸包
    - 基础版本 `StaticConvexHull.cpp`
    - 复数版本 `StaticConvexHullComplex.cpp`

### 其他算法 `/Others`
- 128位整数类型 `Int128.cpp`
- 有序集合工具 `order_of_key.cpp`

### 压力测试 `/StressTest`
- 对拍程序 `stress.cpp`
- 标准程序 `stress__Good.cpp`
- 数据生成器 `stress__Generator.cpp`
- 结果比较器 `compare.cpp`

## 使用说明

1. 所有模板均已在主流 OJ 平台（如 Codeforces、AtCoder、Luogu）上通过测试
2. 代码实现追求以下特点：
   - 正确性：经过大量测试用例验证
   - 可靠性：处理了边界情况和特殊输入
   - 效率性：时间和空间复杂度最优
   - 可读性：变量命名规范，结构清晰
3. 每个文件都包含：
   - 实现原理说明
   - 时间复杂度分析
   - 使用示例
   - 注意事项
4. 可以使用 StressTest 目录下的工具进行对拍测试

## 代码规范

1. 语言标准：C++20
2. 命名规范：
   - 类名：大驼峰命名（PascalCase）
   - 函数名：小驼峰命名（camelCase）
   - 变量名：下划线命名（snake_case）
3. 代码风格：
   - 使用 4 空格缩进
   - 运算符两侧加空格
   - 花括号换行对齐
4. 模板特点：
   - 优先使用 STL 和现代 C++ 特性
   - 关键操作有性能注释
   - 模块化设计，易于集成
   - 预留修改接口

## 注意事项

1. 使用建议：
   - 比赛前先完整阅读相关模板
   - 理解算法原理和使用条件
   - 注意数据范围和时间限制
   - 必要时进行适当修改
2. 常见问题：
   - 整数溢出：注意使用 `long long` 或 `__int128`
   - 浮点精度：根据需要调整 EPS 常量
   - 内存限制：部分算法可能需要修改为在线处理
3. 调试技巧：
   - 使用 `assert` 检查关键条件
   - 对拍时注意数据生成的覆盖面
   - 关注边界情况和特殊输入

## 贡献指南

欢迎通过以下方式完善此模板库：

1. 代码贡献：
   - 添加新的算法实现
   - 优化已有代码性能
   - 补充测试数据
2. 文档改进：
   - 补充使用说明
   - 添加题目练习
   - 修正文档错误
3. 提交要求：
   - 提供完整的测试用例
   - 说明算法的适用范围
   - 注明参考资料和改进点

## License

MIT License - 可以自由使用、修改和分发，但需保留版权声明 