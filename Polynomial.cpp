#include<iostream>
using namespace std;

class Polynomial
{
  private:
    // Variables to store information about polynomial
    int coeffecient[10];
    int degree;
  public:
    Polynomial()
    {
      // Behavior of default constructor
      degree = 0;
      
    }

    Polynomial(int deg)
    {
      // Behavior of constructor with arguments
      degree = deg;
    }
  
    ~Polynomial()
    {
      // Behavior of destructor
      //cout<<"\nDestructing";
    }
  
    //  Overload copy constructor, +, - and = operators
    Polynomial operator + (Polynomial const &obj){
    	Polynomial temp;
    	int small;
    	if(this->degree > obj.degree){
    		temp.degree = this->degree;
    		small = obj.degree;
		}else{
			temp.degree = obj.degree;
			small = this->degree;
		}
    	for(int i=temp.degree;i>=0;i--){
    		if(i<=small){
    			temp.coeffecient[i] = obj.coeffecient[i] + this->coeffecient[i];
			}else{
				if(this->degree > obj.degree){
					temp.coeffecient[i] = this->coeffecient[i];
				}else{
					temp.coeffecient[i] = obj.coeffecient[i];
				}
				
			}
		}
    	return temp;
	}
	Polynomial operator - (Polynomial const &obj){
    	Polynomial temp;
    	int small;
    	if(this->degree > obj.degree){
    		temp.degree = this->degree;
    		small = obj.degree;
		}else{
			temp.degree = obj.degree;
			small = this->degree;
		}
    	for(int i=temp.degree;i>=0;i--){
    		if(i<=small){
    			temp.coeffecient[i] = this->coeffecient[i] - obj.coeffecient[i]  ;
			}else{
				if(this->degree > obj.degree){
					temp.coeffecient[i] = this->coeffecient[i];
				}else{
					temp.coeffecient[i] = -obj.coeffecient[i];
				}
				
			}
		}
    	return temp;
	}
  
    void storePolynomial()
    {
      //  Code to enter and store polynomial
      for(int i=degree;i>=0;i--){
      	cout<<"\nEnter The Coffecient of X^"<<i<<" : ";
      	cin>>coeffecient[i];
	  }
      
    }
    void display()
    {
      //  Code to print the polynomial in readable format
      
      for(int i=degree,j=0;i>=0;i--){
      	
	      	if(coeffecient[i]>0){
	      			if(j>0)
	      			cout<<"+";
	      			
	      			
					if(i==1){
						if(coeffecient[i]!=1){
							cout<<coeffecient[i]<<"x";
							j++;	
						}else{
							cout<<"x";
							j++;	
						}
							
	      				
					}else if(i!=0){
						if(coeffecient[i]!=1){
							cout<<coeffecient[i]<<"x^"<<i;
							j++;	
						}else{
							cout<<"x^"<<i;
							j++;
						}
						
					}else{
						cout<<coeffecient[i];
						j++;
					}
	      			
			}else if(coeffecient[i]<0){
					if(i==1){
						if(coeffecient[i]!=1){
							cout<<coeffecient[i]<<"x";
							j++;	
						}else{
							cout<<"x";
							j++;	
						}
							
	      				
					}else if(i!=0){
						if(coeffecient[i]!=1){
							cout<<coeffecient[i]<<"x^"<<i;
							j++;	
						}else{
							cout<<"x^"<<i;
							j++;
						}
						
					}else{
						cout<<coeffecient[i];
						j++;
					}
			}
      	
	  	}
    }
    
  
};

int main()
{
  int degFirst, degSecond;
  // Ask user to input the values of degFirst and degSecond 
  cout<<"Enter The degree of first polynomial : ";
  cin>>degFirst;
  cout<<"Enter The Degree of second polynomial : ";;
  cin>>degSecond;
  
  	Polynomial firstPolynomial(degFirst);
	Polynomial secondPolynomial(degSecond);
  	Polynomial thirdPolynomial;
  
  cout<<"\nEnter The Coeffecient of 1st Polynomial :-\n";
  firstPolynomial.storePolynomial();
  cout<<"\n\nEnter The Coeffecient of 2nd Polynomial :-\n";
  secondPolynomial.storePolynomial();
  
  thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  cout<<"\n1st Polynomial 					: ";
  firstPolynomial.display();
  cout<<"\n2nd Polynomial 					: ";
  secondPolynomial.display();
  cout<<"\nAfter Adding 1st And 2nd Polynomial 		: ";
  thirdPolynomial.display();
   cout<<"\nAfter Subtracting 2nd polynomial from 1st 	: ";
  fourthPolynomial.display();
	return 0;
}
