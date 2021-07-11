

//..............interfaces............

trait Fruit{
  var fruitType :String
  var weight :Double
}

trait Tiny_Fruit extends Fruit{}

trait Medium_Fruit extends Fruit{}

trait Huge_Fruit extends Fruit{}

trait Oval_Shaped extends Fruit{}

trait Circular_Shaped extends Fruit{}

trait Berry extends Fruit{}


//..............classes............

class Apple extends Medium_Fruit with Oval_Shaped{
  override var fruitType: String = "Apple"
  override var weight: Double = 100
}
class Avocado extends Medium_Fruit with Oval_Shaped{
  override var fruitType: String = "Avocado"
  override var weight: Double = 110
}
class Mango extends Medium_Fruit with Oval_Shaped{
  override var fruitType: String = "Mango"
  override var weight: Double = 250
}
class Pineapple extends Huge_Fruit with Oval_Shaped{
  override var fruitType: String = "Pineapple"
  override var weight: Double = 1100
}


class Grapes extends Tiny_Fruit with Circular_Shaped{
  override var fruitType: String = "Grapes"
  override var weight: Double = 7
}
class Orange extends Medium_Fruit with Circular_Shaped{
  override var fruitType: String = "Orange"
  override var weight: Double = 120
}
class Peaches extends Medium_Fruit with Circular_Shaped{
  override var fruitType: String = "Peaches"
  override var weight: Double = 70
}



class Blueberries extends Tiny_Fruit with Berry{
  override var fruitType: String = "Blueberries"
  override var weight: Double = 6
}
class Blackberries extends Tiny_Fruit with Berry{
  override var fruitType: String = "Blackberries"
  override var weight: Double = 5
}
class Elderberries extends Tiny_Fruit with Berry{
  override var fruitType: String = "Elderberries"
  override var weight: Double = 4
}
class Gooseberries extends Tiny_Fruit with Berry{
  override var fruitType: String = "Gooseberries"
  override var weight: Double = 3
}



