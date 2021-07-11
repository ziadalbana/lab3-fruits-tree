
object Main extends App {
  var fruit : FruitBST = new FruitBST()
  fruit.insert(new Apple())
  fruit.insert(new Orange())
  fruit.insert(new Peaches())
  fruit.insert(new Mango())
  fruit.insert(new Grapes())
  fruit.insert(new Blackberries())
  fruit.insert(new Blueberries())
  fruit.insert(new Avocado())
  fruit.insert(new Apple())

  fruit.iterate()
  println("*******************************\n")

  fruit.findHeaviest()
  println("*******************************\n")

  fruit.findLightest()
  println("*******************************\n")

  fruit.magnifyByType("Apple",600)
  fruit.iterate()
  println("*******************************\n")

  fruit.filterByType("Apple")
  println("*******************************\n")

  fruit.filterByWeight(100)
  println("*******************************\n")
  
}