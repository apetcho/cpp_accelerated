#include<algorithm>
#include<iomanip>
#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>

/** compute the median of a `vector<double>`*/
double median(std::vector<double> vec){
    using size_type = std::vector<double>::size_type;
    size_type size = vec.size();

    if(size == 0){
        throw std::domain_error("median of an empty vector");
    }
    std::sort(vec.begin(), vec.end());

    size_type mid = size/2;
    auto result = size % 2 == 0 ?
        (vec[mid] + vec[mid-1]) / 2 :
        vec[mid];

    return result;
}


/** Compute a student's the overall grade from midterm and final exam grades
 * and homework grade */
double grade(double midterm, double final, double homework){
    return 0.2*midterm + 0.4*final + 0.4*homework;
}

/** Compute a student grade's overall grade from midterm and final exam grades
 * and vector of home work grades.
 * 
 * This function does not copy its arguments, because `median' does so for us.*/
double grade(double midterm, double final, const std::vector<double>& homework){
    if(homework.size() == 0){
        throw std::domain_error("student has done no homework");
    }
    return grade(midterm, final, median(homework));
}

/** Read homework from an input stream info a `vector<double>' */
std::istream& read_homework(std::istream& stream, std::vector<double>& homework)
{
    if(stream){
        // get rid of previous contents
        homework.clear();
        // read homework grades
        double x;
        while(stream >> x){
            homework.push_back(x);
        }
        // clear the stream so that input will work for the next student
        stream.clear();
    }

    return stream;
}

//
int main(){
    // ask for and read the student's name
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    std::cout << "\nHello, " << name << "!" << std::endl;

    // ask for and read the midterm and final grades
    std::cout << "Please enter your midterm and final exam grades: ";
    double midterm;
    double final;
    std::cin >> midterm >> final;
    std::cout << std::endl;


    // ask for the homework grades
    std::cout << "Enter all your homework grades, "
              << "and followed by end-of-file: ";
    std::vector<double> homework;

    
    // read the homework grades
    read_homework(std::cin, homework);
    std::cout << std::endl;

    // compute and generate the final grade, if possible
    try{
        double final_grade = grade(midterm, final, homework);
        std::streamsize prec = std::cout.precision();
        std::cout << "\nYour final grade is " << std::setprecision(3)
            << final_grade << std::setprecision(prec) << std::endl;
    }catch(std::domain_error){
        std::cout << std::endl
            << "You must enter your grades. "
            << "Please try again." << std::endl;

        return EXIT_FAILURE;
    }
    

    return EXIT_SUCCESS;
}
