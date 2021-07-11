import scala.collection.mutable.ListBuffer
class FruitBST {
  var root:FruitTree = nullNode;

  def insert(nodeFruit: Fruit) = root = root.insert(nodeFruit)

  def iterate() = root.iterate()

  def filterByType(fruitType: String) = root.filterByType(fruitType)

  def filterByWeight(fruitWeight: Int) = root.filterByWeight(fruitWeight);

  def magnifyByType(fruitType: String, fruitWeight: Int) = deleteAl(fruitType,fruitWeight,root).foreach(insert)

  def findHeaviest() = root.findHeaviest()

  def findLightest() = root.findLightest()



  private def getParent(treeNode:FruitTree,root:FruitTree):FruitTree = {
    root match {
      case TreeNode(_, left, right) if(left.equals(treeNode)||right.equals(treeNode)) => root;
      case TreeNode(_, left, right) => {
        val parent = getParent(treeNode,left)
        parent match {
          case TreeNode(_, _, _) => parent
          case _ => getParent(treeNode,right)
        }
      }
      case nullNode => nullNode
    }
  }

  private def getSuccessor(treeNode:FruitTree):FruitTree = {
    treeNode match {
      case TreeNode(_,_,right)=> setLeft(right)
      case nullNode => nullNode
    }
  }

  private def setLeft(treeNode:FruitTree) : FruitTree = {
    treeNode match {
      case TreeNode(_,left,_) =>{
        left match {
          case TreeNode(_, _, _) => setLeft(left)
          case _ => treeNode
        }
      }
      case _ => treeNode;
    }
  }

  private def deleteAl(fruitType: String, fruitWeight: Int,nodeTree :FruitTree): ListBuffer[Fruit] = {
    val list = new ListBuffer[Fruit]()
    nodeTree match {
      case TreeNode(nodeFruit,left, right) => {
        list.addAll(deleteAl(fruitType,fruitWeight,left))
        list.addAll(deleteAl(fruitType,fruitWeight,right))
        if (nodeFruit.fruitType.equals(fruitType)){
          deleteTreeNode(nodeTree)
          nodeFruit.weight += fruitWeight
          list.addOne(nodeFruit)
        }
      }
      case _ => {}
    }
    list;
  }

  private def deleteTreeNode(treeNode:FruitTree){
    def deleteNodeFromParent(nodeTree:FruitTree){
      val parent : FruitTree = getParent(nodeTree,root)
      parent match {
        case TreeNode(_, left, _) =>{
          val par:TreeNode = parent.asInstanceOf[TreeNode]
          if (left.equals(treeNode))
            par.left = nullNode;
          else
            par.right = nullNode;
        }
      }
    }

    treeNode match {
      case TreeNode(_,_,_) => {
        val successor:FruitTree = getSuccessor(treeNode)
        successor match {
          case TreeNode(_,_,_) => {
            treeNode.asInstanceOf[TreeNode].nodeFruit = successor.asInstanceOf[TreeNode].nodeFruit
            deleteNodeFromParent(successor)
          }
          case _ => deleteNodeFromParent(treeNode)
        }
      }
      case _ =>{}
    }
  }
}