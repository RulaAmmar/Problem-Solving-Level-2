

#include <iostream>
#include<cstdlib>
using namespace std;

enum enQuestionLevel
{
EasyLevel=1,MedLevel=2,HardLevel=3,MixLevel=4
};

enum enOperationType
{
Add=1,Sub=2,Mul=3,Div=4,Mix=5
};

struct strQuestion
{
    short Number1;
    short Number2;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    short PlayerAnswer;
    short CorrectAnswer;
    bool AnswerResult;
};

struct strQuiz
{
    strQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    short NumberOfRightAnswer=0;
    short NumberOfWrongAnswer=0;
    bool IsPass;
};

short ReadHowManyQuestion() {

    short NumberOfQuestions;

    do {

        cout << "How Many Questions do you want to answer ?";

        cin >> NumberOfQuestions;

    }while(NumberOfQuestions<1||NumberOfQuestions>10);

    return NumberOfQuestions;
}

enQuestionLevel ReadQuestionLevel() {

    short QuestionLevel;

    do {
        cout << "\nEnter Question Level [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix ?";

        cin >> QuestionLevel;

    } while (QuestionLevel<1||QuestionLevel>4);

    return (enQuestionLevel)QuestionLevel;
}

enOperationType ReadOpType() {

    short OpType;

    do {
        cout << "\nEnter Operation Type [1]:Add, [2]:Sub ,[3]:Mul, [4]:Div, [5]:Mix ?";

        cin >> OpType;

    } while (OpType<1||OpType>5);

    return (enOperationType)OpType;
}

void ResetScreen() {
    system("cls");
    system("color 0F");
}

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

int SimpleCalculator(int Number1,int Number2,enOperationType OperationType) {

    switch (OperationType) {

    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mul:
        return Number1 * Number2;
    case enOperationType::Div:
        return Number1 / Number2;
    }
}

strQuestion GenerateQuestion(enQuestionLevel QuestionLevel,enOperationType OperationType) {

    strQuestion Question;

    if (QuestionLevel == enQuestionLevel::MixLevel) {

     QuestionLevel=(enQuestionLevel)RandomNumber(1, 3);

    }
    if (OperationType == enOperationType::Mix) {

        OperationType = (enOperationType)RandomNumber(1, 4);
    }

    Question.OperationType = OperationType;

    Question.QuestionLevel = QuestionLevel;

    switch (QuestionLevel) {
    case enQuestionLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
        return Question;

    case enQuestionLevel::MedLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.CorrectAnswer=SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
        return Question;

    case enQuestionLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
        return Question;
    }
}

void GenerateQuizQuestions(strQuiz &Quiz) {

    for (short Question = 0; Question < Quiz.NumberOfQuestions; Question++) {

       Quiz.QuestionList[Question] = GenerateQuestion(Quiz.QuestionLevel, Quiz.OperationType);
    }
}

string GetOpTypeSymbol(enOperationType OpType) {

    switch (OpType) {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mul:
        return "*";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

void PrintTheQuestion(strQuiz Quiz,short NumberOfQuestion) {

    cout << "\n\nQuestion[" << NumberOfQuestion+1 << "/" << Quiz.NumberOfQuestions << "]\n\n";

    cout << Quiz.QuestionList[NumberOfQuestion].Number1 << endl;

    cout << Quiz.QuestionList[NumberOfQuestion].Number2;

    cout << " " << GetOpTypeSymbol(Quiz.QuestionList[NumberOfQuestion].OperationType)<<endl;

    cout << "------------\n";
}

int ReadQuestionAnswer() {
    int Answer;
    cin >> Answer;
    return Answer;
}

void SetScreenColor(bool Result) {
    if (Result) {
        system("color 2F");
    }
    else {
        system("color 4F");
        cout << "\a";
    }
}

void CorrectTheQuestionAnswer(strQuiz &Quiz,short QuestionNumber) {

    if (Quiz.QuestionList[QuestionNumber].CorrectAnswer == Quiz.QuestionList[QuestionNumber].PlayerAnswer) {
        cout << "Right Answer :-)";
        Quiz.QuestionList[QuestionNumber].AnswerResult = true;
        Quiz.NumberOfRightAnswer++;
    }
    else {
        cout << "Wrong Answer :-(\n";
        cout << "The Riht Answer is : ";
        cout << Quiz.QuestionList[QuestionNumber].CorrectAnswer << endl;
        Quiz.QuestionList[QuestionNumber].AnswerResult = false;
        Quiz.NumberOfWrongAnswer++;
    }

    SetScreenColor(Quiz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswer(strQuiz &Quiz) {

    for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++) {

        PrintTheQuestion(Quiz, QuestionNumber);

        Quiz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

        CorrectTheQuestionAnswer(Quiz,QuestionNumber);
    }
    Quiz.IsPass = Quiz.NumberOfRightAnswer >= Quiz.NumberOfWrongAnswer;
}

string GetFinalResultText(bool QuizResult) {
    if (QuizResult)
        return "PASS :-)";
    else
        return "FAIL :-(";
}

string GetQuestionLevelText(enQuestionLevel QuestionLevel) {
    string arrQuestionLevel[4] = { "Easy","Med","Hard","Mix" };
    return arrQuestionLevel[QuestionLevel - 1];
}

void PrintQuizResult(strQuiz Quiz) {
    cout << "\n-------------------------------------------\n\n";
    cout << "Final Result is " << GetFinalResultText(Quiz.IsPass);
    SetScreenColor(Quiz.IsPass);
    cout << "\n\n-------------------------------------------\n\n";
    cout << "Number Of Questions      : " << Quiz.NumberOfQuestions << endl;
    cout << "Question Level           : " << GetQuestionLevelText(Quiz.QuestionLevel) << endl;
    cout << "OpType                   : " << GetOpTypeSymbol(Quiz.OperationType) << endl;
    cout << "Number Of Right Answer   : " << Quiz.NumberOfRightAnswer << endl;
    cout << "Number of Wrong Answer   : " << Quiz.NumberOfWrongAnswer << endl;
    cout << "-------------------------------------------\n\n";

}

void PlayMathGame() {
    strQuiz Quiz;
    Quiz.NumberOfQuestions = ReadHowManyQuestion();
    Quiz.QuestionLevel = ReadQuestionLevel();
    Quiz.OperationType = ReadOpType();

    GenerateQuizQuestions(Quiz);
    AskAndCorrectQuestionListAnswer(Quiz);
    PrintQuizResult(Quiz);
}

void StartGame() {

    char PlayAgain;

    do {
        ResetScreen();
        PlayMathGame();
        cout << "Do you want to play again Y/N ?";
        cin >> PlayAgain;
    } while (PlayAgain=='y'||PlayAgain=='Y');


}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}


