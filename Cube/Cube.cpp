#include "Cube.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia(std::string str);

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}
bool loadMedia(std::string str)
{
    //Loading success flag
    bool success = true;
    //Load texture
    gTexture = loadTexture(str.c_str());
    if (gTexture == NULL)
    {
        printf("Failed to load texture image!\n");
        success = false;
    }
    //Nothing to load
    return success;
}
void close()
{
    //Free loaded image
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
SDL_Texture* loadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}
/*void Cube::colorEdges()
{
    for (int i = 0; i < 12; ++i)
    {
        int origPos = edges[i].origPosition;
        int origRot = edges[i].rotation;
        for (int j = 0; j < 12; ++j)
        {
            ;
            for (int k = 0; k < 2; ++k)
            {
                if(  )
            }
        }

    }
}*/
void Cube::colorCorners()
{
    corners[0].origPosition;
    corners[0].rotation;
    ;
}
void Cube::colorPieces()
{
    ;
}
void Cube::makeCube()
{
    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!loadMedia("viewport.png"))
        {
            printf("Failed to load media!\n");
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while (!quit)
            {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
                //Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);
                std::vector<std::vector<std::vector<SDL_Rect>>> cubeStickers;
                for (int i = 0; i < 6; ++i)
                {
                    int faceX;
                    int faceY;
                    switch (i)
                    {
                    case 0:
                        loadMedia("white.bmp");
                        faceX = SCREEN_WIDTH / 4;
                        faceY = 0;
                        break;
                    case 1:
                        loadMedia("orange.bmp");
                        faceX = 0;
                        faceY = SCREEN_HEIGHT / 3;
                        break;
                    case 2:
                        loadMedia("green.bmp");
                        faceX = SCREEN_WIDTH / 4;
                        faceY = SCREEN_HEIGHT / 3;
                        break;
                    case 3:
                        loadMedia("red.bmp");
                        faceX = SCREEN_WIDTH / 2;
                        faceY = SCREEN_HEIGHT / 3;
                        break;
                    case 4:
                        loadMedia("blue.bmp");
                        faceX = (3 * SCREEN_WIDTH) / 4;
                        faceY = SCREEN_HEIGHT / 3;
                        ;
                        break;
                    case 5:
                        loadMedia("yellow.bmp");
                        faceX = SCREEN_WIDTH / 4;;
                        faceY = (2 * SCREEN_HEIGHT) / 3;
                        break;
                    }
                    std::vector<std::vector<SDL_Rect>> face;
                    for (int j = 0; j < 3; ++j)
                    {
                        int rowX = (j * SCREEN_HEIGHT) / 9;
                        std::vector<SDL_Rect> row;
                        for (int k = 0; k < 3; ++k)
                        {
                            int colY = (k * SCREEN_WIDTH) / 12;
                            SDL_Rect piece;
                            piece.x = rowX + faceX;
                            piece.y = colY + faceY;
                            piece.w = SCREEN_WIDTH / 12;
                            piece.h = SCREEN_HEIGHT / 9;
                            SDL_RenderSetViewport(gRenderer, &piece);
                            SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
                            row.push_back(piece);
                        }
                        face.push_back(row);
                    }
                    cubeStickers.push_back(face);
                }
                //Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }
    //Free resources and close SDL
    close();
}

std::string Cube::moves = "FRULBDfrulbd";
std::string Cube::toString()
{
    std::string str = "";
    for (int i = 0; i < 12; ++i)
    {
        if (edges[i].origPosition < 10)
        {
            str += "0";  // really only required when origPosition = 0,1 ? normalizing to 2 digits
        }
        str += std::to_string(edges[i].origPosition);
    }

    for (int i = 0; i < 8; ++i)
    {
        str += std::to_string(corners[i].origPosition);
    }

    for (int i = 0; i < 8; ++i)
    {
        str += std::to_string(corners[i].rotation);
    }

    for (int i = 0; i < 12; ++i)
    {
        str += std::to_string(edges[i].rotation);
    }
    return str;

}
double Cube::toDouble()
{
    double d = 0;
    for (int i = 0; i < 12; ++i)
    {
        d += edges[i].origPosition;
        d *= 12;
    }
    for (int i = 0; i < 8; ++i)
    {
        d += corners[i].origPosition;
        d *= 8;
    }
    for (int i = 0; i < 8; ++i)
    {
        d += corners[i].rotation;
        d *= 3;
    }
    for (int i = 0; i < 12; ++i)
    {
        d += edges[i].rotation;
        d *= 2;
    }
    return d;
}
void Cube::initialize()
{
    for (int i = 0; i < 8; ++i)
    {
        corners[i].origPosition = i;
        corners[i].rotation = 0;
    }
    for (int i = 0; i < 12; ++i)
    {
        edges[i].origPosition = i;
        edges[i].rotation = 0;
    }
}
bool Cube::operator==(Cube c)
{
    for (int i = 0; i < 8; ++i)
    {
        if (this->corners[i].origPosition != c.corners[i].origPosition || this->corners[i].rotation != c.corners[i].rotation)
        {
            std::cout << "Equality failed in corners when i=" << i << " because ";
            if (this->corners[i].origPosition != c.corners[i].origPosition)
            {
                std::cout << "origPosition did not match" << std::endl;
            }
            if (this->corners[i].rotation != c.corners[i].rotation)
            {
                std::cout << "rotation did not match" << std::endl;
                std::cout << "this.rotation: " << this->corners[i].rotation << "; c.rotation: " << c.corners[i].rotation << std::endl;
            }
            return false;
        }
    }
    for (int i = 0; i < 12; ++i)
    {
        if (this->edges[i].origPosition != c.edges[i].origPosition || this->edges[i].rotation != c.edges[i].rotation)
        {
            std::cout << "Equality failed in edges when i=" << i << " because ";
            if (this->edges[i].origPosition != c.edges[i].origPosition)
            {
                std::cout << "origPosition did not match" << std::endl;
            }
            if (this->edges[i].rotation != c.edges[i].rotation)
            {
                std::cout << "rotation did not match" << std::endl;
                std::cout << "this.rotation: " << this->edges[i].rotation << "; c.rotation: " << c.edges[i].rotation << std::endl;
            }
            return false;
        }
    }
    return true;
}
std::vector<int> getCornerVector(int i)  // Either pass in corners[x], or x.
{
    std::vector<int> result;
    int x, y, z;
    x = (i % 2) ? 1 : -1;
    y = i < 3 ? -1 : 1;
    z = (i % 4) < 2 ? 1 : -1;
    result.push_back(x);
    result.push_back(y);
    result.push_back(z);
    return result;
}
std::vector<int> getEdgeVector(int i)
{
    std::vector<int> result;
    int x, y, z;
    if (i == 1 || i == 4 || i == 6 || i == 9)
    {
        x = -1;
    }
    else if (i == 0 || i == 3 || i == 8 || i == 11)
    {
        x = 0;
    }
    else
    {
        x = 1;
    }
    if (i == 3 || i == 6 || i == 7 || i == 11)
    {
        z = -1;
    }
    else if (i == 1 || i == 2 || i == 9 || i == 10)
    {
        z = 0;
    }
    else
    {
        z = 1;
    }
    y = i % 4 - 1;

    result.push_back(x);
    result.push_back(y);
    result.push_back(z);
    return result;
}
std::vector<int> addVector(std::vector<int> v1, std::vector<int> v2)
{
    std::vector<int> result;
    for (int i = 0; i < 3; ++i)
    {
        result.push_back(v1.at(i) + v2.at(i));
    }
    return result;
}
std::vector<int> subtractVector(std::vector<int> v1, std::vector<int> v2)
{
    std::vector<int> result;
    for (int i = 0; i < 3; ++i)
    {
        result.push_back(v1.at(i) - v2.at(i));
    }
    return result;
}
int cornerIterator(int corner, int newPos, int numTimes)
{
    return 0;
}
int edgeIterator(int edge, int newPos, int numTimes)
{
    return 0;
}
Cube Cube::operator+(Cube c)
{
    Cube result;
    result.initialize();
    for (int i = 0; i < 12; ++i)
    {
        result.edges[i].origPosition = this->edges[c.edges[i].origPosition].origPosition;
        result.edges[i].rotation = (c.edges[i].rotation + this->edges[c.edges[i].origPosition].rotation) % 2;
    }
    for (int i = 0; i < 8; ++i)
    {
        result.corners[i].origPosition = this->corners[c.corners[i].origPosition].origPosition;
        result.corners[i].rotation = (this->corners[c.corners[i].origPosition].rotation + c.corners[i].rotation) % 3;
    }
    return result;
}
Cube Cube::operator!()
{
    Cube result;
    result.initialize();
    for (int i = 0; i < 12; ++i)
    {
        int a = this->edges[i].origPosition;
        result.edges[a].origPosition = i;
        result.edges[a].rotation = (2 - this->edges[i].rotation) % 2;  // Yes, this is the same as just setting it to this->edges[i].rotation, but not the case for corners
    }
    for (int i = 0; i < 8; ++i)
    {
        int a = this->corners[i].origPosition;
        result.corners[a].origPosition = i;
        result.corners[a].rotation = (3 - this->corners[i].rotation) % 3;
    }
    return result;
}
Cube Cube::operator-(Cube c)
{
    return *this + !c;
}
bool Cube::equals(Cube c, int numCorners, int cornerList[], int numEdges, int edgeList[]) const
{
    for (int i = 0; i < numCorners; ++i)
    {
        Corner c1 = c.corners[i];
        Corner c2 = corners[i];
        if (c1.origPosition != c2.origPosition || c1.rotation != c2.rotation)
        {
            return false;
        }
    }
    for (int i = 0; i < numEdges; ++i)
    {
        Edge e1 = c.edges[i];
        Edge e2 = edges[i];
        if (e1.origPosition != e2.origPosition || e1.rotation != e2.rotation)
        {
            return false;
        }
    }
    return true;
}

void Cube::permuteCorners(int corner[], bool isClockwise)
{
    Corner temp = corners[corner[0]];
    if (isClockwise)
    {
        corners[corner[0]] = corners[corner[3]];
        corners[corner[3]] = corners[corner[2]];
        corners[corner[2]] = corners[corner[1]];
        corners[corner[1]] = temp;
        return;
    }
    corners[corner[0]] = corners[corner[1]];
    corners[corner[1]] = corners[corner[2]];
    corners[corner[2]] = corners[corner[3]];
    corners[corner[3]] = temp;
}
void Cube::rotateCorners(int corner[], int rotationAmount)
{
    corners[corner[0]].rotation = (corners[corner[0]].rotation + rotationAmount) % 3;
    corners[corner[1]].rotation = (corners[corner[1]].rotation + rotationAmount) % 3;
    corners[corner[2]].rotation = (corners[corner[2]].rotation + rotationAmount) % 3;
    corners[corner[3]].rotation = (corners[corner[3]].rotation + rotationAmount) % 3;
}
void Cube::permuteEdges(int edge[], bool isClockwise)
{
    Edge temp = edges[edge[0]];
    if (isClockwise)
    {
        edges[edge[0]] = edges[edge[3]];
        edges[edge[3]] = edges[edge[2]];
        edges[edge[2]] = edges[edge[1]];
        edges[edge[1]] = temp;
        return;
    }
    edges[edge[0]] = edges[edge[1]];
    edges[edge[1]] = edges[edge[2]];
    edges[edge[2]] = edges[edge[3]];
    edges[edge[3]] = temp;
}
void Cube::rotateEdges(int edge[])
{
    edges[edge[0]].rotation = (edges[edge[0]].rotation + 1) % 2;
    edges[edge[1]].rotation = (edges[edge[1]].rotation + 1) % 2;
    edges[edge[2]].rotation = (edges[edge[2]].rotation + 1) % 2;
    edges[edge[3]].rotation = (edges[edge[3]].rotation + 1) % 2;
}

void Cube::F()
{
    int cornerArray[4] = { 0, 1, 3, 2 };
    int edgeArray[4] = { 0, 2, 3, 1 };
    Corner temp = corners[1];
    corners[1] = corners[0];
    corners[0] = corners[2];
    corners[2] = corners[3];
    corners[3] = temp;

    corners[0].rotation = (corners[0].rotation + 2) % 3;
    corners[1].rotation = (corners[1].rotation + 1) % 3;
    corners[2].rotation = (corners[2].rotation + 1) % 3;
    corners[3].rotation = (corners[3].rotation + 2) % 3;

    Edge eTemp = edges[0];
    edges[0] = edges[1];
    edges[1] = edges[3];
    edges[3] = edges[2];
    edges[2] = eTemp;

    edges[0].rotation = (edges[0].rotation + 1) % 2;
    edges[1].rotation = (edges[1].rotation + 1) % 2;
    edges[2].rotation = (edges[2].rotation + 1) % 2;
    edges[3].rotation = (edges[3].rotation + 1) % 2;
}
void Cube::f()
{
    int cornerArray[4] = { 0, 1, 3, 2 };
    int edgeArray[4] = { 0, 2, 3, 1 };
    Corner temp = corners[2];
    corners[2] = corners[0];
    corners[0] = corners[1];
    corners[1] = corners[3];
    corners[3] = temp;

    corners[0].rotation = (corners[0].rotation + 2) % 3;
    corners[1].rotation = (corners[1].rotation + 1) % 3;
    corners[2].rotation = (corners[2].rotation + 1) % 3;
    corners[3].rotation = (corners[3].rotation + 2) % 3;

    Edge eTemp = edges[0];
    edges[0] = edges[2];
    edges[2] = edges[3];
    edges[3] = edges[1];
    edges[1] = eTemp;

    edges[0].rotation = (edges[0].rotation + 1) % 2;
    edges[1].rotation = (edges[1].rotation + 1) % 2;
    edges[2].rotation = (edges[2].rotation + 1) % 2;
    edges[3].rotation = (edges[3].rotation + 1) % 2;
}
void Cube::B()
{
    // rotates corners 4-7 clockwise
    int cornerArray[4] = { 2, 3, 7, 6 };
    int edgeArray[4] = { 3, 7, 11, 6 };

    Corner temp = corners[6];
    corners[6] = corners[4];
    corners[4] = corners[5];
    corners[5] = corners[7];
    corners[7] = temp;

    corners[4].rotation = (corners[4].rotation + 1) % 3;
    corners[5].rotation = (corners[5].rotation + 2) % 3;
    corners[6].rotation = (corners[6].rotation + 2) % 3;
    corners[7].rotation = (corners[7].rotation + 1) % 3;

    Edge eTemp = edges[8];
    edges[8] = edges[10];
    edges[10] = edges[11];
    edges[11] = edges[9];
    edges[9] = eTemp;

    edges[8].rotation = (edges[8].rotation + 1) % 2;
    edges[9].rotation = (edges[9].rotation + 1) % 2;
    edges[10].rotation = (edges[10].rotation + 1) % 2;
    edges[11].rotation = (edges[11].rotation + 1) % 2;
}
void Cube::b()
{
    // rotates corners 4-7 anticlockwise
    int cornerArray[4] = { 2, 3, 7, 6 };
    int edgeArray[4] = { 3, 7, 11, 6 };
    Corner temp = corners[5];
    corners[5] = corners[4];
    corners[4] = corners[6];
    corners[6] = corners[7];
    corners[7] = temp;

    corners[4].rotation = (corners[4].rotation + 1) % 3;
    corners[5].rotation = (corners[5].rotation + 2) % 3;
    corners[6].rotation = (corners[6].rotation + 2) % 3;
    corners[7].rotation = (corners[7].rotation + 1) % 3;

    Edge eTemp = edges[8];
    edges[8] = edges[9];
    edges[9] = edges[11];
    edges[11] = edges[10];
    edges[10] = eTemp;

    edges[8].rotation = (edges[8].rotation + 1) % 2;
    edges[9].rotation = (edges[9].rotation + 1) % 2;
    edges[10].rotation = (edges[10].rotation + 1) % 2;
    edges[11].rotation = (edges[11].rotation + 1) % 2;
}
void Cube::R()
{
    // Rotates odd corners clockwise
    int cornerArray[4] = { 1, 5, 7, 3 };
    int edgeArray[4] = { 2, 5, 10, 7 };

    Corner temp = corners[1];
    corners[1] = corners[3];
    corners[3] = corners[7];
    corners[7] = corners[5];
    corners[5] = temp;

    corners[1].rotation = (corners[1].rotation + 2) % 3;
    corners[3].rotation = (corners[3].rotation + 1) % 3;
    corners[5].rotation = (corners[5].rotation + 1) % 3;
    corners[7].rotation = (corners[7].rotation + 2) % 3;

    //clockwise: 2, 5, 10, 7
    Edge eTemp = edges[2];
    edges[2] = edges[7];
    edges[7] = edges[10];
    edges[10] = edges[5];
    edges[5] = eTemp;

    edges[2].rotation = (edges[2].rotation + 1) % 2;
    edges[5].rotation = (edges[5].rotation + 1) % 2;
    edges[7].rotation = (edges[7].rotation + 1) % 2;
    edges[10].rotation = (edges[10].rotation + 1) % 2;
}
void Cube::r()
{
    // Rotates odd corners anticlockwise
    int cornerArray[4] = { 1, 5, 7, 3 };
    int edgeArray[4] = { 2, 5, 10, 7 };
    Corner temp = corners[1];
    corners[1] = corners[5];
    corners[5] = corners[7];
    corners[7] = corners[3];
    corners[3] = temp;

    corners[1].rotation = (corners[1].rotation + 2) % 3;
    corners[3].rotation = (corners[3].rotation + 1) % 3;
    corners[5].rotation = (corners[5].rotation + 1) % 3;
    corners[7].rotation = (corners[7].rotation + 2) % 3;

    Edge eTemp = edges[2];
    edges[2] = edges[5];
    edges[5] = edges[10];
    edges[10] = edges[7];
    edges[7] = eTemp;

    edges[2].rotation = (edges[2].rotation + 1) % 2;
    edges[5].rotation = (edges[5].rotation + 1) % 2;
    edges[7].rotation = (edges[7].rotation + 1) % 2;
    edges[10].rotation = (edges[10].rotation + 1) % 2;
}
void Cube::L()
{   // Rotates even corners clockwise
    int cornerArray[4] = { 0, 2, 6, 4 };
    int edgeArray[4] = { 1, 6, 9, 4 };
    Corner temp = corners[0];
    corners[0] = corners[4];
    corners[4] = corners[6];
    corners[6] = corners[2];
    corners[2] = temp;

    corners[0].rotation = (corners[0].rotation + 1) % 3;
    corners[2].rotation = (corners[2].rotation + 2) % 3;
    corners[4].rotation = (corners[4].rotation + 2) % 3;
    corners[6].rotation = (corners[6].rotation + 1) % 3;

    // clockwise: 1, 6, 9, 4
    Edge eTemp = edges[1];
    edges[1] = edges[4];
    edges[4] = edges[9];
    edges[9] = edges[6];
    edges[6] = eTemp;

    edges[1].rotation = (edges[1].rotation + 1) % 2;
    edges[4].rotation = (edges[4].rotation + 1) % 2;
    edges[6].rotation = (edges[6].rotation + 1) % 2;
    edges[9].rotation = (edges[9].rotation + 1) % 2;
}
void Cube::l()
{
    // Rotates even corners anticlockwise
    int cornerArray[4] = { 0, 2, 6, 4 };
    int edgeArray[4] = { 1, 6, 9, 4 };
    Corner temp = corners[0];
    corners[0] = corners[2];
    corners[2] = corners[6];
    corners[6] = corners[4];
    corners[4] = temp;

    corners[0].rotation = (corners[0].rotation + 1) % 3;
    corners[2].rotation = (corners[2].rotation + 2) % 3;
    corners[4].rotation = (corners[4].rotation + 2) % 3;
    corners[6].rotation = (corners[6].rotation + 1) % 3;

    // clockwise: 1, 6, 9, 4
    Edge eTemp = edges[1];
    edges[1] = edges[6];
    edges[6] = edges[9];
    edges[9] = edges[4];
    edges[4] = eTemp;

    edges[1].rotation = (edges[1].rotation + 1) % 2;
    edges[4].rotation = (edges[4].rotation + 1) % 2;
    edges[6].rotation = (edges[6].rotation + 1) % 2;
    edges[9].rotation = (edges[9].rotation + 1) % 2;
}
void Cube::U()
{
    Corner temp = corners[0];
    corners[0] = corners[1];
    corners[1] = corners[5];
    corners[5] = corners[4];
    corners[4] = temp;

    Edge eTemp = edges[0];
    edges[0] = edges[5];
    edges[5] = edges[8];
    edges[8] = edges[4];
    edges[4] = eTemp;
}
void Cube::u()
{
    Corner temp = corners[0];
    corners[0] = corners[4];
    corners[4] = corners[5];
    corners[5] = corners[1];
    corners[1] = temp;

    Edge eTemp = edges[0];
    edges[0] = edges[4];
    edges[4] = edges[8];
    edges[8] = edges[5];
    edges[5] = eTemp;
}
void Cube::D()
{
    Corner temp = corners[2];
    corners[2] = corners[6];
    corners[6] = corners[7];
    corners[7] = corners[3];
    corners[3] = temp;

    Edge eTemp = edges[3];
    edges[3] = edges[6];
    edges[6] = edges[11];
    edges[11] = edges[7];
    edges[7] = eTemp;
}
void Cube::d()
{
    Corner temp = corners[2];
    corners[2] = corners[3];
    corners[3] = corners[7];
    corners[7] = corners[6];
    corners[6] = temp;

    Edge eTemp = edges[3];
    edges[3] = edges[7];
    edges[7] = edges[11];
    edges[11] = edges[6];
    edges[6] = eTemp;
}
Cube Cube::operator=(Cube c)
{
    for (int i = 0; i < 12; ++i)
    {
        this->edges[i] = c.edges[i];
    }
    for (int i = 0; i < 8; ++i)
    {
        this->corners[i] = c.corners[i];
    }
    return *this;
}
Cube Cube::makeMoves(std::string moves)
{
    Cube cu;
    cu.initialize();
    cu = *this;
    for (int i = 0; i < moves.size(); ++i)
    {
        char ch = moves.at(i);
        switch (ch)
        {
        case 'F':
            cu.F(); break;
        case 'f':
            cu.f(); break;
        case 'B':
            cu.B(); break;
        case 'b':
            cu.b(); break;
        case 'U':
            cu.U(); break;
        case 'u':
            cu.u(); break;
        case 'D':
            cu.D(); break;
        case 'd':
            cu.d(); break;
        case 'R':
            cu.R(); break;
        case 'r':
            cu.r(); break;
        case 'L':
            cu.L(); break;
        case 'l':
            cu.l(); break;
        }
    }
    return cu;
}

std::vector<std::string> Cube::getScrambles(int numMoves)
{
    std::string permutation = "";
    std::vector < std::string> result;
    int prevMove = -1;
    int twoPrevMove = -1;
    char twoPrev = 'X';
    char prev = 'Y';
    char cur = 'Z';
    for (int i = 0; i < pow(12, numMoves); ++i)
    {
        bool broken = false;
        permutation = "";
        for (int j = 0; j < numMoves; ++j)
        {

            int k = i / pow(12, j);
            if (permutation.size() != 0)
            {
                if ((k + 12 - prevMove) % 12 == 6)
                {
                    broken = true;
                    break;
                }
                k = (k + 12) % 12;
                if (permutation.size() > 1)
                {
                    twoPrev = Cube::moves.at(twoPrevMove);
                    if (twoPrev == prev && prev == cur)
                    {
                        broken = true;
                        break;
                    }
                    // set twoPrevMove
                }
                prev = Cube::moves.at(prevMove);
                cur = Cube::moves.at(k);

                // never do F/f after B/b
                if ((prev == 'B' || prev == 'b') && (cur == 'F') || (cur == 'f'))
                {
                    broken = true;
                    break;
                }
                // never do L/l after R/r
                if ((prev == 'R' || prev == 'r') && (cur == 'L') || (cur == 'l'))
                {
                    broken = true;
                    break;
                }
                // never do U/u after D/d
                if ((prev == 'D' || prev == 'd') && (cur == 'U') || (cur == 'u'))
                {
                    broken = true;
                    break;
                }
                if (prev == 'u' && cur == 'u')
                {
                    broken = true;
                    break;
                }
                if (prev == 'd' && cur == 'd')
                {
                    broken = true;
                    break;
                }
                if (prev == 'l' && cur == 'l')
                {
                    broken = true;
                    break;
                }
                if (prev == 'r' && cur == 'r')
                {
                    broken = true;
                    break;
                }
                if (prev == 'f' && cur == 'f')
                {
                    broken = true;
                    break;
                }
                if (prev == 'b' && cur == 'b')
                {
                    broken = true;
                    break;
                }
            }
            k = (k + 12) % 12;
            twoPrevMove = prevMove;
            prevMove = k;
            permutation.push_back(Cube::moves.at(k % 12));
        }
        if (broken)
        {
            continue;
        }
        result.push_back(permutation);
    }
    return result;
}
int stringCompare(std::string str1, std::string str2)
{
    return strcmp(str1.c_str(), str2.c_str());
}

class StateMovePair
{
private:
    std::vector<std::string> pair;
    double d;
public:
    std::vector<std::string> getPair()
    {
        return pair;
    }
    double getDouble()
    {
        return d;
    }
    StateMovePair(std::string s1, double f)
    {
        pair.push_back(s1);

        d = f;
    }
};
/*bool vcmp(StateMovePair smp1, StateMovePair smp2)
{
    return strcmp(smp1.getPair()[0].c_str(), smp2.getPair()[0].c_str()) < 0;
}*/
bool dcmp(StateMovePair smp1, StateMovePair smp2)
{
    return smp1.getDouble() < smp2.getDouble();
}
std::string compareLists(std::vector<StateMovePair> list1, std::vector<StateMovePair> list2)
{
    long i = 0;
    long j = 0;
    double cmp = 1;

    //while ( cmp = stringCompare(c1Strings[i].getPair()[0], c2Strings[j].getPair()[0]) )
    while (true)
    {
        cmp = list1[i].getDouble() - list2[j].getDouble();
        if (cmp < 0)
        {
            if (i + 1 < list1.size())
            {
                ++i;
            }
            else
            {
                return "";
            }
        }
        else if (cmp > 0)
        {
            if (j + 1 < list1.size())
            {
                ++j;
            }
            else
            {
                return "";
            }
        }
        else if (cmp == 0)
        {
            std::cout << "Moves required for first  cube is: " << list1[i].getPair()[0] << std::endl;
            std::cout << "Moves required for second cube is: " << list2[j].getPair()[0] << std::endl;
            std::string unscramble = list2[j].getPair()[0];
            std::reverse(unscramble.begin(), unscramble.end());
            std::string correctCase = "";
            for (int x = 0; x < unscramble.size(); ++x)
            {
                char c = unscramble.at(x);
                if (std::isupper(c))
                {
                    correctCase += std::tolower(c);
                }
                else
                {
                    correctCase += std::toupper(c);
                }
            }

            std::cout << "Unscramble: " << correctCase + list1[i].getPair()[0] << std::endl;
            return correctCase + list1[i].getPair()[0];
        }
    }
    return "";
}
std::string splitAndCompareLists(int numLists, std::vector<StateMovePair> c1Strings, std::vector<StateMovePair> c2Strings)
{
    std::vector<std::vector<StateMovePair>> lists1, lists2;
    int listSize = c1Strings.size() / numLists;
    for (int i = 0; i < numLists; ++i)
    {
        std::vector<StateMovePair> l1, l2;
        for (int j = 0; j < listSize; ++j)
        {
            int pos = i * listSize + j;
            l1.push_back(c1Strings.at(pos));
            l2.push_back(c2Strings.at(pos));
        }
        lists1.push_back(l1);
        lists2.push_back(l2);
    }
    for (int x = 0; x < numLists; ++x)
    {
        std::sort(lists1.at(x).begin(), lists1.at(x).end(), dcmp);
        std::sort(lists2.at(x).begin(), lists2.at(x).end(), dcmp);
        std::string output;
        for (int i = 0; i < x; ++i)
        {
            std::cout << "1) calling compareLists with list1(" << x << "); list2(" << i << ")" << std::endl;
            if ((output = compareLists(lists1.at(x), lists2.at(i))) != "")
            {
                return output;
            }
            std::cout << "2) calling compareLists with list1(" << i << "); list2(" << x << ")" << std::endl;
            if ((output = compareLists(lists1.at(i), lists2.at(x))) != "")
            {
                return output;
            }
        }
        std::cout << "3) calling compareLists with list1(" << x << "); list2(" << x << ")" << std::endl;
        if ((output = compareLists(lists1.at(x), lists2.at(x))) != "")
        {
            return output;
        }
    }
    return "";
}
int main(int argc, char* args[])
{
    Cube base, x, y, z;
    base.initialize();
    x.initialize();
    y.initialize();
    z.initialize();

    
    Cube c1;
    c1.initialize();
    Cube c2;
    c2.initialize();
    int edges[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int corners[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    //std::string a = "dllURRfDUlFb"; std::vector<std::string> twoMoves = Cube::getScrambles(6);
    std::string a = "RUFD"; std::vector<std::string> twoMoves;

    c1 = c1.makeMoves(a);

    std::cout << "Result of scrambling cube: " << c1.toString() << std::endl;
    //std::cout << "Number of scrambles: " << twoMoves.size() << std::endl;


    for( int x = 1 ; x < 5 ; ++x )
    {
        std::vector<StateMovePair> c1Strings, c2Strings;
        twoMoves = Cube::getScrambles(x);
        for (long i = 0; i < twoMoves.size(); ++i)
        {
            std::string move = twoMoves.at(i);
            StateMovePair smp1(move, c1.makeMoves(move).toDouble());
            StateMovePair smp2(move, c2.makeMoves(move).toDouble());
            c1Strings.push_back(smp1);
            c2Strings.push_back(smp2);
        }
        std::string output;
        if ((output = splitAndCompareLists(1, c1Strings, c2Strings)) != "")
        {
            // check if doing output to c1 makes it solved
            c1 = c1.makeMoves(output);

            return 1;
        }
    }

    //The window we'll be rendering to
    /*
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);

            //Fill the surface white
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            //Update the surface
            SDL_UpdateWindowSurface(window);

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
        }
    }

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    //Start up SDL and create window
    SDL_Rect stickers[12][9];
    //stickers[0][0].

    if (!init())
    {
        printf("Failed to initialize!\n");
    }*/

    /*
    else
    {
        //Load media
        if (loadMedia("red.bmp"))
        {
            printf("Failed to load media!\n");
        }
        else
        {
            // sho
            SDL_Renderer* gRenderer = NULL;
            SDL_Rect red;
            red.x = 100;
            red.y = 100;
            red.w = 100;
            red.h = 100;
            SDL_Rect green;
            green.x = 200;
            green.y = 300;
            green.w = 100;
            green.h = 100;
            while (true)
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, SDL_ALPHA_TRANSPARENT);
                SDL_RenderDrawRect(gRenderer, &red);
                SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawRect(gRenderer, &green);
                SDL_RenderPresent(gRenderer);
            }

            // sho
            //Apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

            //Update the surface
            SDL_UpdateWindowSurface(gWindow);

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
        }
    }*/
    //Free resources and close SDL
    //close();

    return 0;
}