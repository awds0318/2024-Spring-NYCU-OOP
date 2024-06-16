#include"dm.h"

int main(int argc ,char* argv[])
{

	///----- parse file
    ifstream input_file(argv[1]);
    int nShape; ///# of total shapes
    int nTri=0,nRec=0,nSqu=0,nCir=0;

    input_file >> nShape;

    shape** shape_list = new shape*[nShape];
    string in_shape, in_name;

    for(int i=0 ; i<nShape ; i++){
      input_file >> in_name >> in_shape;
      if(in_shape == "triangle"){
        double a, b, c;
        input_file >> a >> b >> c;
        triangle *t_ptr = new triangle(a,b,c,in_name);
        shape_list[i] = t_ptr;
        nTri ++ ;
      }
      else if(in_shape == "circle") {
        double r;
        input_file >> r;
        circle *c_ptr = new circle(r,in_name);
        shape_list[i] = c_ptr;
        nCir ++ ;
      }
      else if(in_shape == "rectangle") {
        double a, b, c, d;
        input_file >> a >> b >> c >> d;
        rectangle *r_ptr = new rectangle(a,b,c,d,in_name);
        shape_list[i] = r_ptr;
        nRec ++ ;
      }
      else if(in_shape == "square") {
        double a, b, c, d;
        input_file >> a >> b >> c >> d;
        square *s_ptr = new square(a,b,c,d,in_name);
        shape_list[i] = s_ptr;
        nSqu ++ ;
      }
    }

    for(int i=0 ; i<nShape ; i++){
      shape_list[i]->set_perimeter();
    }

    cout<<"[# of each shape]"<<endl;
    cout<<"Triangle: "<<nTri<<endl;
	  cout<<"Rectangle: "<<nRec<<endl;
	  cout<<"Square: "<<nSqu<<endl;
	  cout<<"Circle: "<<nCir<<endl;
	  cout<<endl;

    cout<<"[Legal]"<<endl;
    for(int i=0 ; i<nShape ; i++){
      if(shape_list[i]->get_perimeter() != -1)
        shape_list[i]->get_information();
    }

    cout<<"[Illegal]"<<endl;
    for(int i=0 ; i<nShape ; i++){
      if(shape_list[i]->get_perimeter() == -1)
        shape_list[i]->get_information();
    }
	
    return 0;
}
