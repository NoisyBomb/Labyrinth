#include "labirint.h"

size_t Labirint::DynamicMemory = 0;

size_t Labirint::MaxMemory = 0;


void initcells(int cells[][2], int row,int col,int&topiw){
    cells[topiw][0]=row;
    cells[topiw][1]=col;
    topiw++;
}

void shuffle(int arr[][2]) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        int temp[2];
        for (int j = 0; j < 2; j++) {
            temp[j] = arr[i][j];
            arr[i][j] = arr[randomIndex][j];
            arr[randomIndex][j] = temp[j];
        }
    }
}
bool Labirint::isPathExist(ElementLabirinta **maze, int startRow, int startCol, int finishRow, int finishCol) {
    if(maze==nullptr){return false;}
    srand(static_cast<unsigned int>(time(nullptr)));
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool visited[ROWS][COLS] = {false};
    int stacki[ROWS * COLS][2];
    int top = 0;
    stacki[top][0] = startRow;
    stacki[top][1] = startCol;
    top+=1;
    visited[startRow][startCol] = true;

    while (top > 0) {
        top-=1;
        int current[1][2];
        current[0][0]= stacki[top][0];
        current[0][1]=stacki[top][1];
        int row = current[0][0];
        int col = current[0][1];
        if (row == finishRow && col == finishCol) {
            return true;
        }
        shuffle(dirs);
        for (int i = 0; i < 4; ++i) {
            int nextRow = row + dirs[i][0];
            int nextCol = col + dirs[i][1];
            if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && ((maze[nextRow][nextCol].Getwall0()) == 0) && !visited[nextRow][nextCol]) {
                stacki[top][0] = nextRow;
                stacki[top][1] = nextCol;
                top+=1;
                visited[nextRow][nextCol] = true;
            }
        }
    }
    return false;
}
void Labirint::generateMaze(ElementLabirinta **maze, int &numPaths) {
    if(maze==nullptr){return;}
    if(numPaths<0){return;}
    srand(static_cast<unsigned int>(time(nullptr)));
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int topiw=0;
    int cells[COLS*ROWS][2];
    int startRow=rand()%ROWS;
    int startCol=rand()%COLS;
    initcells(cells,startRow,startCol,topiw);
    while (topiw!=0) {
        int cellIndex = rand() % topiw;
        int row = cells[cellIndex][0];
        int col = cells[cellIndex][1];
        int neighbors[4];
        int neighborstop=0;
        for (int i = 0; i < 4; ++i){
            int nextRow = row + dirs[i][0]* 2;
            int nextCol = col + dirs[i][1]* 2;
            if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && ((maze[nextRow][nextCol].Getwall0())== 1)) {
                neighbors[neighborstop]=i;
                ++neighborstop;
            }
            //cout<<nextRow<<" "<<nextCol<<endl;
            //view_labi();getchar();
        }
        if (neighborstop!=0){
            int dirIndex = neighbors[rand()%neighborstop];
            int nextRow = row +dirs[dirIndex][0]*2;
            int nextCol = col +dirs[dirIndex][1]*2;
            maze[nextRow][nextCol].InitWall(0);
            maze[row + (dirs[dirIndex][0])][col + (dirs[dirIndex][1])].InitWall(0);
            numPaths--;
            initcells(cells,nextRow,nextCol,topiw);
        }
        if (neighborstop == 0) {
            for (int i = cellIndex; i < topiw - 1; i++) {
                cells[i][0] = cells[i + 1][0];
                cells[i][1] = cells[i + 1][1];
            }
            topiw--;
        }
    }
}

Labirint::Labirint(size_t a,int mod){
    ROWS = a;COLS=a;
    if(mod==1){
    srand(static_cast<unsigned int>(time(0)));
    setMemCounter(0,0);
    int ROWSCOLS=ROWS;
    bool est=false;
    create_labi();
    init_labi();
    int startRow, startCol, finishRow, finishCol;
    try {
        cout << "Enter the starting point coordinates (row and column): ";
        if (!(cin >> startRow >> startCol) || startRow < 0 || startCol < 0 || startRow >= a || startCol >= a) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw runtime_error("Invalid input for starting point coordinates.");
        }
        cout << "Enter the finishing point coordinates (row and column): ";
        if (!(cin >> finishRow >> finishCol) || finishRow < 0 || finishCol < 0 || finishRow >= a || finishCol >= a) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw runtime_error("Invalid input for finishing point coordinates.");
        }
    }catch (const exception& e) {
        cerr << e.what() << endl;
        exit(1);
     }
    init_kordinats_start(startRow, startCol);
    init_kordinats_finish(finishRow, finishCol);
    startsx3y3(startRow, startCol,finishRow, finishCol);
    labi[startRow][startCol].InitWall(0);
    int numPaths = ROWS * COLS-1;
    generateMaze(labi, numPaths);
    labi[finishRow][finishCol].InitWall(0);
    null_visiter();
    view_labi();
    while (true){
        est = isPathExist(labi, startRow, startCol, finishRow, finishCol);
        if(est){
            break;
        }
        if(!est){
            int tu=0;
            while(tu!=ROWSCOLS*ROWSCOLS){
                    est = isPathExist(labi, startRow, startCol, finishRow, finishCol);
                    if(est==true){break;}
                    tu++;
            }
            //cout<<est;
            if(!est){
                init_labi();
                labi[startRow][startCol].InitWall(0);
                int numPaths = ROWS * COLS;
                generateMaze(labi, numPaths);
                labi[finishRow][finishCol].InitWall(0);
            }
            else{break;}
        }
        if(est){break;}
    }
    cout<<endl<<endl;
    view_labi();
    }
    if(mod==2){
    srand(static_cast<unsigned int>(time(0)));
    setMemCounter(0,0);
    int ROWSCOLS=ROWS;
    bool est=false;
    create_labi();
    init_labi();
    int startRow =0, startCol = 0, finishRow = ROWS-1, finishCol = COLS-1;
    init_kordinats_start(startRow, startCol);
    init_kordinats_finish(finishRow, finishCol);
    startsx3y3(startRow, startCol,finishRow, finishCol);
    labi[startRow][startCol].InitWall(0);
    int numPaths = ROWS * COLS-1;
    generateMaze(labi, numPaths);
    labi[finishRow][finishCol].InitWall(0);
    view_labi();
    while (true){
        est = isPathExist(labi, startRow, startCol, finishRow, finishCol);
        if(est){
            break;
        }
        if(!est){
            int tu=0;
            while(tu!=ROWSCOLS*ROWSCOLS){
                    est = isPathExist(labi, startRow, startCol, finishRow, finishCol);
                    if(est==true){break;}
                    tu++;
            }
            //cout<<est;
            if(!est){
                init_labi();
                labi[startRow][startCol].InitWall(0);
                int numPaths = ROWS * COLS;
                generateMaze(labi, numPaths);
                labi[finishRow][finishCol].InitWall(0);
            }
            else{break;}
        }
        if(est){break;}
    }
    }
}


Labirint::~Labirint()
{
    for(int i =0;i<ROWS;i++){
        memDown(sizeof(ElementLabirinta) * COLS);
        delete[] labi[i];
    }
    memDown(sizeof(ElementLabirinta*) * ROWS);
    delete[] labi;
    for(int i =0;i<ROWS;i++){
        memDown(sizeof(bool) * COLS);
        delete[] visiter[i];
    }
    memDown(sizeof(bool*) * ROWS);
    delete[] visiter;
    for(int i =0;i<ROWS*COLS;i++){
        memDown(sizeof(bool) * 2);
        delete[] uzls[i];
    }
    memDown(sizeof(bool*) * ROWS*COLS);
    delete[] uzls;
}

void Labirint::memUp(size_t newMem)
{
    DynamicMemory += newMem;
    if(DynamicMemory > MaxMemory){
        MaxMemory = DynamicMemory;
    }
}

void Labirint::memDown(size_t delMem)
{
    if(DynamicMemory >= delMem){
        DynamicMemory -= delMem;
    } else{
        DynamicMemory = 0;
    }
}

size_t Labirint::getDynMem()
{
    return DynamicMemory;
}

size_t Labirint::getMaxMem()
{
    return MaxMemory;
}

void Labirint::setMemCounter(size_t dm, size_t mm)
{
    DynamicMemory = dm;
    MaxMemory = mm;
}

void Labirint::create_labi(){
    labi=new ElementLabirinta*[ROWS];
    memUp(sizeof(ElementLabirinta*) * ROWS);
    for(int i = 0;i<ROWS;i++){
        labi[i]= new ElementLabirinta[COLS];
        memUp(sizeof(ElementLabirinta) * COLS);
    }
    uzls=new int*[ROWS*COLS];
    memUp(sizeof(int*) * ROWS*COLS);
    for(int i = 0;i<ROWS*COLS;i++){
        uzls[i]= new int[2];
        memUp(sizeof(int) * 2);
    }
    visiter=new bool*[ROWS];
    memUp(sizeof(bool*) * ROWS);
    for(int i = 0;i<ROWS;i++){
        visiter[i]= new bool[COLS];
        memUp(sizeof(bool) * COLS);
    }
}
void Labirint::init_labi(){
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            labi[i][j] = 1;
        }
    }
}


void Labirint::view_labi(){
    for(int i = 0;i<ROWS;i++){
        for(int j = 0;j<COLS;j++){
            if(labi[i][j].Getwall0()==1){cout<<"#";}
            if(labi[i][j].Getwall0()==0){cout<<"-";}}
        cout<<endl;
    }
}


void Labirint::null_labirint(){
    init_top(0);
    null_visiter();
    selectx1y1();
    here_startx3y3();
}
void Labirint::null_uzls(){
    for(int i=0;i<ROWS*COLS;i++){
        for(int j=0;j<2;j++){
            uzls[i][j] = 0;
        }
    }
}
void Labirint::here_startx3y3(){
    visiter[x3][y3]=true;
}
void Labirint::selectx1y1(){
    x1=x3;
    y1=y3;
    x2=x4;
    y2=y4;
}
void Labirint::startsx3y3(int xi,int yi,int xii, int yii){
    x3=xi;
    y3=yi;
    x4=xii;
    y4=yii;
}


void Labirint::null_visiter(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            visiter[i][j]=false;
        }
    }
}
void Labirint::init_top(int top){
    topi=top;
}
void Labirint::getx1y1(){
    cout<<"x3: "<<x3<<" y3: "<<y3<<endl;
    cout<<"x4: "<<x4<<" y4: "<<y4<<endl;
}


bool Labirint::chek_finish(){
    if(x1==x2&&y1==y2){return true;}
    else{return false;}
}


void Labirint::plusuzels(){
    if((topi+1)>ROWS){return;}else{
    visiter[x1][y1]=true;
    uzls[topi][0]=x1;
    uzls[topi][1]=y1;
    topi+=1;
    }
}
void Labirint::veiw_visiter(){
    cout<<endl<<"topi: "<<topi<<" x1: "<<x1<<" y1: "<<y1<<endl;
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            cout<<visiter[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void Labirint::minusuzels(){
    visiter[x1][y1]=true;
    topi-=1;
    if(topi>=0){
        x1 =uzls[topi][0];
        y1 =uzls[topi][1];
        visiter[x1][y1]=false;}
    else{topi+=1;}
}


void Labirint::here_start(){
    visiter[x1][y1]=true;
}


void Labirint::init_kordinats_start(int xi,int yi){
    x1 = xi;
    y1 = yi;
}
void Labirint::init_kordinats_finish(int xi,int yi){
    x2 = xi;
    y2 = yi;
}
void Labirint::goUp(){
    visiter[x1][y1] = true;
    x1-=1;
    visiter[x1][y1] = true;
}
void Labirint::goDown(){
    visiter[x1][y1] = true;
    x1+=1;
    visiter[x1][y1] = true;
}
void Labirint::goRight(){
    visiter[x1][y1] = true;
    y1+=1;
    visiter[x1][y1] = true;
}
void Labirint::goLeft(){
    visiter[x1][y1] = true;
    y1-=1;
    visiter[x1][y1] = true;
}


void Labirint::check_dirs(int *mass){
    setlocale(LC_ALL,"RUS");
    if ((x1-1) >= 0 && (x1-1) < ROWS && y1 >= 0 && y1 < COLS && (visiter[x1-1][y1]==false)&&((labi[x1-1][y1].Getwall0()) == 0)) {
        mass[0]=1;
    }
    if ((x1+1) >= 0 && (x1+1) < ROWS && y1 >= 0 && y1 < COLS && (visiter[x1+1][y1]==false)&&((labi[x1+1][y1].Getwall0()) == 0)) {
        mass[1]=1;
    }
    if ((y1+1) >= 0 && (y1+1) < ROWS && x1 >= 0 && x1 < COLS && (visiter[x1][y1+1]==false)&&((labi[x1][y1+1].Getwall0()) == 0)) {
        mass[2]=1;
    }
    if ((y1-1) >= 0 && (y1-1) < ROWS && x1 >= 0 && x1 < COLS && (visiter[x1][y1-1]==false)&&((labi[x1][y1-1].Getwall0()) == 0)) {
        mass[3]=1;
    }
}


void Labirint::select_dir(int nu){
    switch (nu){
        case 1:{
            goUp();
            break;
        }
        case 2:{
            goDown();
            break;
        }
        case 3:{
            goRight();
            break;
        }
        case 4:{
            goLeft();
            break;
        }
        default:
        {
            break;
        }
    }
}

