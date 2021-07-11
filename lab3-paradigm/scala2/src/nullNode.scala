
case object nullNode extends FruitTree{

  override def insert(nodeFruit: Fruit): FruitTree = TreeNode (nodeFruit,nullNode,nullNode)

  override def iterate()= {}

  override def inOrder(function: FruitTree => Unit) = {}

  override def filterByWeight(fruitWeight: Int)= {}

  override def filterByType(fruitType: String)= {}

  override def findHeaviest()= println("Empty tree")

  override def findLightest()= println("Empty tree")
}