
case class TreeNode (var nodeFruit : Fruit,var left : FruitTree , var right : FruitTree) extends FruitTree {



  override def insert(nodeFruit: Fruit) = {
    def inner_insert(tree:FruitTree , nodeFruit:Fruit):FruitTree = tree match {
      case TreeNode(data,left, right) if (data.weight >= nodeFruit.weight) => TreeNode(data,inner_insert(left,nodeFruit),right)
      case TreeNode(data,left, right) if (data.weight < nodeFruit.weight) => TreeNode(data,left,inner_insert(right,nodeFruit))
      case nullNode => tree.insert(nodeFruit)
    }
    inner_insert(this,nodeFruit)
  }

  override def iterate(): Unit =  inOrder((treeNode:FruitTree) => printNode(treeNode.asInstanceOf[TreeNode]))


  override def inOrder(function: FruitTree => Unit)= {
    this.left.inOrder(function)
    function(this)
    this.right.inOrder(function)
  }

  override def filterByWeight(fruitWeight: Int)= {
    def inner_filterByWeight(treeNode : FruitTree) {
      treeNode match {
        case TreeNode(data,_,right) if (data.weight < fruitWeight) => inner_filterByWeight(right)
        case TreeNode(data,left,right) if (data.weight >= fruitWeight) => {
          inner_filterByWeight(left)
          println("Type = "+data.fruitType +", Weight = "+ data.weight)
          inner_filterByWeight(right)
        }
        case nullNode => treeNode.filterByWeight(fruitWeight)
      }
    }
    inner_filterByWeight(this)
  }

  override def filterByType(fruitType: String)= {
    inOrder((treeNode:FruitTree)=>{
      if (treeNode.asInstanceOf[TreeNode].nodeFruit.fruitType.equals(fruitType))
        printNode(treeNode.asInstanceOf[TreeNode])
    })
  }

  def printNode(treeNode:TreeNode) = println(">> "+treeNode.nodeFruit.fruitType +", Weight = "+ treeNode.nodeFruit.weight)

  override def findHeaviest(){
    def inner_findHeaviest(treeNode : FruitTree){
      treeNode match {
        case TreeNode(_, _, right) => right match {
            case TreeNode(_, _, _) => inner_findHeaviest(right)
            case _ => printNode(treeNode.asInstanceOf[TreeNode])
          }
        case _ => treeNode.findHeaviest()
      }
    }
    inner_findHeaviest(this)
  }

  override def findLightest() {
    def inner_findLightest(treeNode : FruitTree) {
      treeNode match {
        case TreeNode(_,left, _) => left match {
            case TreeNode(_,_, _) => inner_findLightest(left)
            case _ => printNode(treeNode.asInstanceOf[TreeNode])
          }
        case _ => treeNode.findLightest();
      }
    }
    inner_findLightest(this)
  }

}