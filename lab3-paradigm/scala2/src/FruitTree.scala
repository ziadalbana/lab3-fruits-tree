
trait FruitTree{
  def insert(nodeFruit: Fruit) : FruitTree
  def iterate()
  def inOrder(function:FruitTree => Unit)
  def filterByType(fruitType:String)
  def filterByWeight(fruitWeight:Int)
  def findHeaviest()
  def findLightest()
}
