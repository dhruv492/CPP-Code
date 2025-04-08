#include<iostream>
using namespace std;

class Rectangle
{
    int Length, Width, Area, Perimeter;

    public:
        void SetDimensions(int l, int w)
        {
            Length = l;
            Width = w;
        }

        int CalculateArea()
        {
            Area = Length*Width;
            return Area;
        }

        int CalculatePerimeter()
        {
            Perimeter = 2*(Length + Width);
            return Perimeter;
        }

        int ReturnLength()
        {
            return Length;
        }

        int ReturnWidth()
        {
            return Width;
        }
};

int main()
{
    Rectangle R[10];
    int Choice=0,Count=0;
    int Length,Width,Area,Perimeter;

    do
    {
        cout<<"\n\nChoices:\n1.Add Rectangle,\n2.Update Dimensions of Rectangle,\n3.View Existing Rectangles\n0.Exit System\nEnter your Choice: ";
        cin>>Choice;

        switch (Choice)
        {
            case 1:
                Count++;
                cout << "\nEnter Dimensions of New Rectangle " << Count << endl;
                cin >> Length >> Width;
                R[Count].SetDimensions(Length,Width);
                cout << "\nNew Rectangle Added!";
                cout << "\nTotal " << Count << " Rectangles in System";
                cout << "\nArea of Rectangle " << Count << " is " << R[Count].CalculateArea() << " sq. units.";
                cout << "\nPerimeter of Rectangle " << Count << " is " << R[Count].CalculatePerimeter() << " units.";
                break;

            case 2:
                int s;
                if(Count==0)
                {
                    cout << "\nNO Rectangles in System\nExiting...";
                    break;
                }
                else
                {
                    cout << "Enter the Serial no. of the Rectangle of which to Update Dimensions: ";
                    cin >> s;
                    cout << "\nEnter new Dimensions of Rectangle:\n";
                    cin >> Length >> Width;
                    R[s-1].SetDimensions(Length,Width);
                    cout << "\nRectangle Updated!";
                    cout << "\nNew Length of Rectangle " << s << " is " << R[s-1].ReturnLength() << " units.";
                    cout << "\nNew Width of Rectangle " << s << " is " << R[s-1].ReturnWidth() << " units.";
                    cout << "\nNew Area of Rectangle " << s << " is " << R[s-1].CalculateArea() << " sq. units.";
                    cout << "\nNew Perimeter of Rectangle " << s << " is " << R[s-1].CalculatePerimeter() << " units.";
                }
                break;

            case 3:

                cout << "\n\nViewing Existing " << Count << " Rectangles";
                if(Count==0)
                {
                    cout<<"\nNO Rectangles in System\nExiting...";
                    break;
                }
                for(int j=0;j<Count;j++)
                {
                    cout << "\n\nRectangle " << j+1;
                    cout << "\nLength of Rectangle " << j+1 << " is " << R[j].ReturnLength() << " units.";
                    cout << "\nWidth of Rectangle " << j+1 << " is " << R[j].ReturnWidth() << " units.";
                    cout << "\nArea of Rectangle " << j+1 << " is " << R[j].CalculateArea() << " sq. units.";
                    cout << "\nPerimeter of Rectangle " << j+1 << " is " << R[j].CalculatePerimeter() << " units.";
                }
                break;

            default:
            break;
        }
    }
    while(Choice>=1 && Choice<=3);

    cout<<"\nExiting System....";
    cout<<"\n\nViewing Existing "<<Count<<" Rectangles";
        for(int j=0;j<Count;j++)
          {
            cout<<"\n\nRectangle "<<j+1;
            cout<<"\nLength of Rectangle "<<j+1<<" is "<<R[j].ReturnLength()<<" units.";
            cout<<"\nWidth of Rectangle "<<j+1<<" is "<<R[j].ReturnWidth()<<" units.";
            cout<<"\nArea of Rectangle "<<j+1<<" is "<<R[j].CalculateArea()<<" sq. units.";
            cout<<"\nPerimeter of Rectangle "<<j+1<<" is "<<R[j].CalculatePerimeter()<<" units.";
        }
    return 0;
}

