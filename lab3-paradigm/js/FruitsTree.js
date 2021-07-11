// tree
function Fruit() {
    this.root = null;
};
// basic node
var fruitnode=  {
    weight: 0,
    name: "name",
    type: "fruit",
    setWeight: function (weight) {
        this.weight = weight;
    },
    getWeight: function () {
        return this.weight;
    },
    setType: function (type) {
        this.type = type;
    },
    getType: function () {
        return this.type;
    },
};
// fruits types
var oval = {
    getshape: function () {
        return "oval";
    },
};

var berry = {
    getshape: function () {
        return "berry";
    },
};

var circular = {
    getshape: function () {
        return "circular";
    },
};

var tiny = {
    getshape: function () {
        return "tiny";
    },
};

var Medium = {
    getshape: function () {
        return "Medium";
    },
};

var huge = {
    getshape: function () {
        return "huge";
    },
};
// BST tree
Fruit.prototype.makeNode=function(fruitObj) {
    // creating a node that will be an object
    let node = Object.create(fruitnode);
    node=fruitObj;
    node.left = null;
    node.right = null;
    return node;
};

Fruit.prototype.insert = function(fruitObj) {
    var temp=this.makeNode(fruitObj);
    var current=this.root;
    //check if the tree is empty
    if(this.root===null) {this.root=temp;}
    else{
        var inserted = false;
        while(!inserted){
            if(temp.weight<current.weight){
                if(current.left===null){
                    current.left=temp;
                    inserted=true;
                    break;
                }else {
                    current=current.left;
                }
            }else if(temp.weight>current.weight){
                if (current.right===null){
                    current.right=temp;
                    inserted=true;
                    break;
                }else{
                    current=current.right;
                }
            }else {
                //duplicate weight
                break;
            }
        }
    }
};
Fruit.prototype.Iterate=function (){
    var inorder=function (node){
        if(node===null) return;
        inorder(node.left);
        Fruit.prototype.println(node);
        inorder(node.right);
    }
    inorder(this.root);
};
Fruit.prototype.filterByType=function (Type){
    var filtered=[];
    var inorder=function (node){
        if(node===null) return;
        inorder(node.left);
        if(node.type.includes(Type)) {
            Fruit.prototype.println(node);
            filtered.push(node);
        }
        inorder(node.right);
    }
    inorder(this.root);
    return filtered;
}
Fruit.prototype.filterByWeight=function (Weight){
    var filtered=[];
    var inorder=function (node){
        if(node===null) return;
        inorder(node.left);
        if(node.weight>Weight) {
            Fruit.prototype.println(node);
            filtered.push(node);
        }
        inorder(node.right);
    }
    inorder(this.root);
    return filtered;
}
Fruit.prototype.magnifyByType=function (Type, Weight){
    const list=[];
    var inorder=function (node){
        if (node===null) return;
        if(node.type===Type) {
            node.weight+=Weight;
        }
        list.push(node);
        inorder(node.left);
        inorder(node.right);
    }
    inorder(this.root);
    var newtree=new Fruit();
    list.forEach(obj=>newtree.insert(obj));
    return newtree;
}

Fruit.prototype.findHeaviest=function (){
    var searchRight=function (node){
        if(node.right===null) return node;
        else return searchRight(node.right);
    }
    return searchRight(this.root);
}
Fruit.prototype.findLightest=function (){
    var searchLeft=function (node){
        if(node.left===null) return node;
        else return searchLeft(node.left);
    }
    return searchLeft(this.root);
}
Fruit.prototype.println=function (node){
    console.log(node.type+" "+node.weight);
}
///////// fruits//////
var apple = Object.create(fruitnode);
apple.setWeight(145);
(apple.setName = function () {
    this.name = "apple";
}
), apple.setName();
apple.setType(Medium.getshape() + " " + oval.getshape() + " " + apple.name);
//////////////////
var avocado = Object.create(fruitnode);
avocado.setWeight(155);
(avocado.setName = function () {
    this.name = "avocado";
}),
    avocado.setName();
avocado.setType(Medium.getshape() + " " + oval.getshape() + " " + avocado.name);
/////////////////
var Mango = Object.create(fruitnode);
Mango.setWeight(180);
(Mango.setName = function () {
    this.name = "Mango";
}),
    Mango.setName();
Mango.setType(Medium.getshape() + " " + oval.getshape() + " " + Mango.name);
////////////////
var Pineapple = Object.create(fruitnode);
Pineapple.setWeight(1200);
(Pineapple.setName = function () {
    this.name = "Pineapple";
}),
    Pineapple.setName();
Pineapple.setType(
    huge.getshape() + " " + oval.getshape() + " " + Pineapple.name
);
////////////////
var Grapes = Object.create(fruitnode);
Grapes.setWeight(2.5);
(Grapes.setName = function () {
    this.name = "Grapes";
}),
    Grapes.setName();

Grapes.setType(tiny.getshape() + " " + circular.getshape() + " " + Grapes.name);
///////////////
var orange = Object.create(fruitnode);
orange.setWeight(130);
(orange.setName = function () {
    this.name = "orange";
}),
    orange.setName();
orange.setType(
    Medium.getshape() + " " + circular.getshape() + " " + orange.name
);
//////////////
var Blackberries = Object.create(fruitnode);
Blackberries.setWeight(5);
(Blackberries.setName = function () {
    this.name = "Blackberries";
}),
    Blackberries.setName();
Blackberries.setType(
    tiny.getshape() + " " + berry.getshape() + " " + Blackberries.name
);
//////////////////
var Peaches = Object.create(fruitnode);
Peaches.setWeight(150);
(Peaches.setName = function () {
    this.name = "Peaches";
}),
    Peaches.setName();
Peaches.setType(
    Medium.getshape() + " " + circular.getshape() + " " + Peaches.name
);
/////////////////
var Blueberries = Object.create(fruitnode);
Blueberries.setWeight(0.5);
(Blueberries.setName = function () {
    this.name = "Blueberries";
}),
    Blueberries.setName();
Blueberries.setType(
    tiny.getshape() + " " + berry.getshape() + " " + Blueberries.name
);
///////////////
var Elderberries = Object.create(fruitnode);
Elderberries.setWeight(0.5);
(Elderberries.setName = function () {
    this.name = "Elderberries";
}),
    Elderberries.setName();
Elderberries.setType(
    tiny.getshape() + " " + berry.getshape() + " " + Elderberries.name
);
//////////////
var Gooseberries = Object.create(fruitnode);
Gooseberries.setWeight(2.3);
(Gooseberries.setName = function () {
    this.name = "Gooseberries";
}),
    Gooseberries.setName();
Gooseberries.setType(
    tiny.getshape() + " " + berry.getshape() + " " + Gooseberries.name
);

var tree=new Fruit();
const arr=[apple,avocado,Mango,Pineapple,Grapes,orange,Blackberries,Peaches,Blueberries,Elderberries,Gooseberries];
// test inserting
arr.forEach(obj=>tree.insert(obj));
tree.Iterate();
console.log("==============================");
tree=tree.magnifyByType("tiny berry Blueberries",7);
tree.Iterate();
console.log("==============================");
tree.println(tree.findHeaviest());
console.log("==============================");
tree.println(tree.findLightest());
console.log("==============================");
tree.filterByType("Medium circular");
console.log("==============================");
tree.filterByWeight(100);

