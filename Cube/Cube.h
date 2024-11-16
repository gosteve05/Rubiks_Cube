#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <algorithm>

class Edge
{
public:
    int origPosition, rotation;
    Edge operator=(Edge e)
    {
        origPosition = e.origPosition;
        rotation = e.rotation;
        return *this;
    }
};
class Corner
{
public:
    int origPosition, rotation;
    Corner operator=(Corner c)
    {
        origPosition = c.origPosition;
        rotation = c.rotation;
        return *this;
    }
};
class Cube
{
private:
    Edge edges[12];  // edges[i] is always at the location of what starts as edges[i]
    Corner corners[8];
    static std::string moves;
    void permuteCorners( int corner[] , bool isClockwise );
    void rotateCorners( int corner[] , int rotationAmount );
    void permuteEdges( int edge[] , bool isClockwise);
    void rotateEdges( int edge[]);
public:
    Cube operator=(Cube c);
    bool operator==(Cube c);
    Cube operator+(Cube c);
    Cube operator-(Cube c);
    Cube operator!();
    void initialize();
    Cube makeMoves(std::string moves);
    std::string toString();
    double toDouble();
    bool equals( Cube c, int numCorners, int cornerList[], int numEdges, int edgeList[]) const;
    static std::vector<std::string> getScrambles(int numMoves);
    void makeCube();
    void colorPieces();
    void colorEdges();
    void colorCorners();
    std::string getMoves();
    void F();
    void f();
    void B();
    void b();
    void R();
    void r();
    void L();
    void l();
    void U();
    void u();
    void D();
    void d();
};