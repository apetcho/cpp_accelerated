#include<algorithm>
#include<iomanip>
#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>

struct StudentInfo{
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
};

/** compute the median of a `vector<double>' */
double median(std::vector<double> vec){
    using size_type = std::vector<double>::size_type;

    size_type size = vec.size();
    if(size == 0){
        throw std::domain_error("median of an empty vector");
    }

    std::sort(vec.begin(), vec.end());
    size_type mid = size / 2;

    auto result = size % 2 ?
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

double grade(const StudentInfo& info){
    return grade(info.midterm, info.final, info.homework);
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

std::istream& read_student_info(std::istream& stream, StudentInfo& record){
    // Read and store the student's name and midterm and final exam grades
    stream >> record.name >> record.midterm >> record.final;
    read_homework(stream, record.homework);
    return stream;
}

bool compute_student_info(const StudentInfo& x, const StudentInfo& y){
    return x.name < y.name;
}

/*******************/
/*   MAIN DRIVER   */
/*******************/
int main(){
    std::vector<StudentInfo> students;
    StudentInfo record;
    std::string::size_type maxlen = 0;

    // read and store all the records, and find the length of the longest name
    std::cout << "Reading students' record ..." << std::endl;
    while(read_student_info(std::cin, record)){
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }

    std::sort(students.begin(), students.end(), compute_student_info);

    using vsize_type = std::vector<StudentInfo>::size_type;
    std::cout << std::endl;
    for(vsize_type i=0; i != students.size(); ++i){
        std::cout << "Computing " << students[i].name
                << "'s final grade ..." << std::endl;
        std::cout << students[i].name
            << std::string(maxlen+1 - students[i].name.size(), ' ');
        // compute and write the grade
        try{
            double final_grade = grade(students[i]);
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3)
                << "final grade is " << final_grade
                << std::setprecision(prec);
        }catch(std::domain_error err){
            std::cout << err.what();
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
