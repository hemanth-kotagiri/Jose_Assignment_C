#include<stdio.h>
# define stud 5 // nani, here you can change the number of students to be any positive integer but not zero.
# define subj 5 // here, you can change the number of subjects each student has taken exam to any positive integer but not zero.

// we use these # define keyword to declare constant values such as the number of students, subjects in this program.

// suppose we have over 100,000 students taking exams of each 27 subjects. Then what would you do? 
// you can simply change the value after stud in line 2 to 100,000 and value of subj in line 3 to 27 and the program will work fine! :)
// you might not know these things, feel free to change the code a bit to your understanding. :)

int main(){
	int students = stud;
	
	int student_marks_avg[stud]; // I am declaring an array to store the avg. marks of each students.
	
	int i = 0, subject; 
	
	// this might look a bit intimidating, but its simple, I will explain tomorrow.
	for(i; i<stud; i++){
		printf("Enter the %d subject marks of student %d\n", subj, i+1);
		
		for(subject = 1; subject <= subj; subject++){
			printf("Marks of subject %d: ", subject);
			
			int curr_sub_mark;
			scanf("%d",&curr_sub_mark); // taking in the marks of respective subject.
			
			if(subject == 1){
				student_marks_avg[i] = curr_sub_mark; // seeing if this is the first subject, if so, then add that marks.
			}else{
				student_marks_avg[i] += curr_sub_mark; // else, we add to the existing marks the new subject marks to avg. out later.
			}
		}
		// this is where we find the avg. We are diving the total of the marks of student by the number of subjects.
		
		student_marks_avg[i] /= subj;
		
		printf("\n"); // this is to make the next line.
	}
	
	// finally, printing avg. of each student.
	
	for(i=0; i<stud; i++){
		printf("\nAvg. marks of student %d = %d\n",i+1,student_marks_avg[i]);
	}
	
	return 0; // again, this is something that you will understand while learning about functions. :*
}
