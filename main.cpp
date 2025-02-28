#include "mainwindow.h"
#include "example_linear_geometry.h"

#include <iostream>

#include <QApplication>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace ExamplePolyredronGeometry;
int main(int argc, char *argv[])
{
    GS gs;
    std::shared_ptr<Group> g{
        new Group
    };
    Polyhedron p;
    HalfSpace ah{SparseVector<Scalar>(MAX_DIM),true},bh{SparseVector<Scalar>(MAX_DIM),false},ch,dh;
    //*
    ah.vec.coeffRef(1)=2;
    ah.vec.coeffRef(2)=1;
    bh.vec.coeffRef(0)=5;
    bh.vec.coeffRef(1)=2;
    bh.vec.coeffRef(2)=-1;
    //*/
    //*
    p.faces.insert(ah);
    p.faces.insert(bh);
    //*
    g->components.insert(p);
    //*
    for(auto p:g->components){
        std::cout<<"next polyhedra\n";
        for(auto h:p.faces){
            std::cout<<h.vec<<' '<<h.is_strong<<'\n';
        }
    }
    std::cout<<"project\n";
    Dim y{2};
    std::shared_ptr<Group> g1=gs.project_parallel(g,y);
    for(auto p:g1->components){
        std::cout<<"next polyhedra\n";
        for(auto h:p.faces){
            std::cout<<h.vec<<' '<<h.is_strong<<'\n';
        }
    }
    //*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
