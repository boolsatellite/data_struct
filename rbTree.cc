//
// Created by satellite on 2023-12-06.
//

/**
 * 红黑树定义：
 * 1. 每个节点都有颜色，不是红色就是黑色
 * 2. root必须是黑色
 * 3. 所有叶子节点都是黑色，叶子节点是NULL，不存储实际数据
 * 4. 每个红色节点必须有两个黑色节点，或者说每个叶子节点到根节点的所有路径上不能有连续的红色节点
 * 5. 从任一节点到其每个叶子节点的搜友简单路径都包含相同数目的黑色节点
 */


/**
 * 红黑树插入：
 *  1. 空树：插入节点为黑色root
 *  2. 树非空：插入节点尽量为红色，若父节点是黑色，则插入完成
 *     若父节点是红色，则要进行插入调整(根据uncle节点的颜色)
 *
 */


