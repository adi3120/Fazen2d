class cloud
{
        float x=s_width;
    float y=10;
public:


    void drawClouds(Fazen2d game)
    {
        std::string cloud[4] = {
            "......######.....",
            ".#####......###..",
            "#..............##",
            ".######..###..#.."};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 17; j++)
            {
                if (cloud[i][j] == '#')
                {
                    game.Plot(x + j, y + i,blueF);
                }
            }
        }
    }
    void move(float time)
    {
        x-=5*time;
        if(x<-11)
        {
            x=s_width;
        }
    }
};