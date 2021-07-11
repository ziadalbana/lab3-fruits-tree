#include "Fruits.h"

class BST
{

public:
    Fruit* root;
    BST();
    Fruit* getroot()
    {
        return root;
    }
    void setroot(Fruit* r)
    {
        root=r;
    }
    virtual Fruit* Insert(Fruit* r, Fruit* n) = 0;
    virtual void  Iterate(Fruit* root) = 0;
    virtual Fruit* deleteNode(Fruit* parent , Fruit* root, Fruit* deleted ) = 0;
};

BST ::BST()
    : root(NULL)
{
}

class FruitsTree : public BST
{
public:
    vector<Fruit*> deleteAndInsert ;


    Fruit* Insert(Fruit* r, Fruit* n) override
    {
        if (r == NULL)
        {
            return n;
        }

        if (((*n).getWeight()) > ((*r).getWeight()))
        {
            (*r).setRight(Insert((*r).getRight(),n));
        }
        else
        {
            (*r).setLeft(Insert((*r).getLeft(),n));
        }
        return r;
    }



    void  Iterate(Fruit* root) override
    {

        if (root == NULL)
        {
            return;
        }
        Iterate((*root).getLeft());
        cout << "Type : "<<(*root).getType() <<"\tWeight:"<< (*root).getWeight() << "\tShape : "<< (*root).getShape() << "\tSize : "<< (*root).getSize() << endl;
        Iterate((*root).getRight());
    }


    void filterByType(Fruit* root,string type)
    {
        if (root == NULL)
        {
            return;
        }
        filterByType((*root).getLeft(),type);
        if((*root).getType()  ==  type)
        {
            cout << "Type : "<<(*root).getType() <<"\tWeight:"<< (*root).getWeight() << "\tShape : "<< (*root).getShape() << "\tSize : "<< (*root).getSize() << endl;
        }
        filterByType((*root).getRight(),type);
    }

    void filterByWeight(Fruit* root,int weight)
    {
        if (root == NULL)
        {
            return;
        }
        filterByWeight((*root).getLeft(),weight);
        if((*root).getWeight()  >=  weight)
        {
            cout << "Type : "<<(*root).getType() <<"\tWeight:"<< (*root).getWeight() << "\tShape : "<< (*root).getShape() << "\tSize : "<< (*root).getSize() << endl;
        }
        filterByWeight((*root).getRight(),weight);
    }

    Fruit* findHeaviest(Fruit* root){
            while (root != NULL && (*root).getRight() != NULL)
            {

                root = ( (*root).getRight() );

            }

    cout <<"The Heaviest :-    " << "Type : "<<(*root).getType() <<"\tWeight:"<< (*root).getWeight() << "\tShape : "<< (*root).getShape() << "\tSize : "<< (*root).getSize() << endl;
    return root;
    }


    Fruit* findLightest(Fruit* root){
            while (root != NULL && (*root).getLeft() != NULL)
            {
                root = (*root).getLeft() ;

            }

    cout <<"The Lightest :-    "<< "Type : "<<(*root).getType() <<"\tWeight:"<< (*root).getWeight() << "\tShape : "<< (*root).getShape() << "\tSize : "<< (*root).getSize() << endl;
    return root;
    }


    Fruit* deleteNode(Fruit* parent , Fruit* r, Fruit* deleted ) override
    {
        if (r == NULL)
            return r;

        if (((*deleted).getWeight()) < ((*r).getWeight())){
                parent = r ;
                (*r).setLeft(deleteNode( parent , (*r).getLeft() , deleted ));
        }
        else if (((*deleted).getWeight()) > ((*r).getWeight())){
                 parent = r ;
                (*r).setRight(deleteNode( parent , (*r).getRight() , deleted ));
        }
        else {
            if(r == deleted){
                if ((*r).getRight() == NULL && (*r).getLeft() == NULL){
                    return NULL;
                }
                else if ( (*r).getLeft() == NULL ) {
                    Fruit* temp = (*r).getRight();
                    return temp;
                }
                else if ((*r).getRight() == NULL) {
                    Fruit* temp = (*r).getLeft();
                    return temp;
                }
                Fruit* temp = deleteMinValue( r , (*r).getRight() );
                if(parent != NULL){
                if(((*r).getWeight()) > ((*parent).getWeight())){
                    (*parent).setRight(temp);
                }else{
                    (*parent).setLeft(temp);
                }
                (*temp).setRight( (*r).getRight() );
                (*temp).setLeft ( (*r).getLeft() );
                return temp;
                }else{
                    (*temp).setRight( (*r).getRight() );
                    (*temp).setLeft ( (*r).getLeft() );
                    root = temp;
                     return root;
                }
            }
            else{
                    parent = r ;
                (*r).setLeft( deleteNode(parent , (*r).getLeft() , deleted ));
            }
        }
        return r;
    }


    Fruit* deleteMinValue(Fruit* parent , Fruit* root)
    {
     while (root != NULL && (*root).getLeft() != NULL)
            {
                parent = root ;
                root = (*root).getLeft() ;
            }
            if(((*root).getWeight()) > ((*parent).getWeight())){
                    (*parent).setRight(NULL);
                }else{
                    (*parent).setLeft(NULL);
                }
            return root;
    }


    void deletedMagnify(Fruit* r,string Type,int Weight)
    {
       if (r == NULL)
        {
            return;
        }
        deletedMagnify((*r).getLeft(),Type , Weight);
        if((*r).getType()  ==  Type)
        {
            root=deleteNode(NULL,root,r);
            (*r).setLeft(NULL);
            (*r).setRight(NULL);
            (*r).weight+=Weight;
            deleteAndInsert.push_back(r);
        }
        deletedMagnify((*r).getRight(),Type,Weight);
    }

    void insertMagnify(){
        for(int i = 0 ; i < deleteAndInsert.size() ; i++ ){
            Insert(root,deleteAndInsert[i]);
        }
        deleteAndInsert.clear();
    }


    void magnifyByType(Fruit* r,string Type,int Weight)
    {
        deletedMagnify(r,Type,Weight);
        insertMagnify();
    }

    };

/*
bst.insert(apple);
bst.insert(orange);
bst.insert(Figs);
bst.insert(Pear);
bst.insert(Peaches);
bst.insert(Mango);
bst.insert(Guava);
bst.insert(Grapes);
bst.insert(Blackberries);
bst.insert(Banana);
bst.insert(Blueberries);
bst.insert(Watermelon);
*/

int main()
{
    FruitsTree tree;

    Apple apple;
    Apple apple2(150);
    Apple apple3(200);
    Orange orange ;
    Figs fig;
    Pear pear;
    Peaches peach;
    Mango mango;
    Guava guava;
    Grapes grape;
    Blackberries blackBerry;
    Banana banana;
    Blueberries blueBerry;
    Watermelon watermelon;

    tree.setroot(tree.Insert(tree.getroot(),&apple));
    tree.setroot(tree.Insert(tree.getroot(),&apple2));
    tree.setroot(tree.Insert(tree.getroot(),&apple3));
    tree.setroot(tree.Insert(tree.getroot(),&orange));
    tree.setroot(tree.Insert(tree.getroot(),&fig));
    tree.setroot(tree.Insert(tree.getroot(),&pear));
    tree.setroot(tree.Insert(tree.getroot(),&peach));
    tree.setroot(tree.Insert(tree.getroot(),&mango));
    tree.setroot(tree.Insert(tree.getroot(),&guava));
    tree.setroot(tree.Insert(tree.getroot(),&grape));
    tree.setroot(tree.Insert(tree.getroot(),&blackBerry));
    tree.setroot(tree.Insert(tree.getroot(),&banana));
    tree.setroot(tree.Insert(tree.getroot(),&blueBerry));
    tree.setroot(tree.Insert(tree.getroot(),&watermelon));

    cout << "\t\t\t Tree"<<endl;
    tree.Iterate(tree.getroot());
    cout <<"\n\n\n"<<endl;

    cout<<"\t\t\t Apple"<<endl;
    tree.filterByType(tree.getroot() , "Apple");
    cout <<"\n\n\n"<<endl;

    cout<<"Fruits greater than or equal 100\n"<<endl;
    tree.filterByWeight(tree.getroot() , 100);
    cout <<"\n\n\n"<<endl;

    cout<<"\t\t\t The heaviest"<<endl;
    tree.findHeaviest(tree.getroot());
    cout <<"\n\n\n"<<endl;

    cout<<"\t\t\t The lightest"<<endl;
    tree.findLightest(tree.getroot() );
    cout <<"\n\n\n"<<endl;

    cout<<"\t\t\t Magnify The apple by 200 gram "<<endl;
    tree.magnifyByType(tree.getroot(),"Apple",200 );
    tree.Iterate(tree.getroot());
    cout <<"\n\n\n"<<endl;


    return 0;
}



