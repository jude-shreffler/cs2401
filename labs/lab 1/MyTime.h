// Add documentation for each function

#include <iostream>
    
class MyTime
{   
  public:

    /**
     * @brief Construct a new My Time object
     * 
     * @param h hour to be set, defaults to 0
     * @param m minutes to be set, defaults to 0
     */
    MyTime(int h = 0, int m = 0);   

    // Member functions

    /**
     * @brief resets the time
     * 
     * @param h the new hour
     * @param m the new minute
     */
    void Reset(int h, int m);

    /**
     * @brief Get the hours object
     * 
     * @return int the hours object
     */
    int get_hours() const{return hours;}

    /**
     * @brief Get the minutes object
     * 
     * @return int the minutes object
     */
    int get_minutes() const{return minutes;}

    /**
     * @brief + operator, adds two times
     * 
     * @param t2 the time on the right of the +
     * @return MyTime an object set to the sum of both times
     */
    MyTime operator + (const MyTime& t2) const;

    /**
     * @brief - operator, subtracts two times
     * 
     * @param t2 the time on the right of the -
     * @return MyTime an object set to the difference of the times
     */
    MyTime operator - (const MyTime& t2) const;

    /**
     * @brief * operator, scales a time
     * 
     * @param num scalar for the time
     * @return MyTime an object with time * scalar
     */
    MyTime operator * (int num) const;

    /**
     * @brief / operator, scales a time
     * 
     * @param num scalar for the time
     * @return MyTime an object with time / scalar
     */
    MyTime operator / (int num) const;

    /**
     * @brief input handler between >> and MyTime
     * 
     * @param ins the istream from >>
     */
    void input(std::istream& ins);

    /**
     * @brief output handler between << and MyTime
     * 
     * @param outs the ostream from <<
     */
    void output(std::ostream& outs)const;

    /**
     * @brief == operator, compares two times
     * 
     * @param t2 object on the right of the ==
     * @return true if both objects have equal times
     * @return false if the objects dont have equal times
     */
    bool operator == (const MyTime& t2)const;

    /**
     * @brief < operator, compares two times
     * 
     * @param t2 object on the right of the <
     * @return true if left is less than right
     * @return false otherwise
     */
    bool operator < (const MyTime& t2)const;

    /**
     * @brief <= operator, compares two times
     * 
     * @param t2 object on the right of the <=
     * @return true if left is <= right
     * @return false otherwise
     */
    bool operator <= (const MyTime& t2)const;
   
  private:
      /**
       * @brief simplifies the time after manipulating it, used in member functions
       * 
       */
      void simplify();
      int hours;        // hours can be > 24
      int minutes;      // 0 <= minutes <= 59
 };

 std::istream& operator >> (std::istream& ins, MyTime& t);
 std::ostream& operator << (std::ostream& outs, const MyTime&);