class ground
{
public:
    float x=s_width;
    float y;
    int c=rand()%3;
    ;
    ground()
    {
        y=(s_height/2-2) +rand()%6;
    }
    void show(Fazen2d game)
    {
        
        std::string rocks[3][1] = {
            {"..##.."},
            {"....##"},
            {"##...."},
            };
            int i=c;
        for(int j=0;j<1;j++)
        {
            for(int k=0;k<6;k++)
            {
                if(rocks[i][j][k]=='#')
                {
                    game.Plot(x+k,y+j);
                }
                else
                {
                    game.Plot(x+k,y+j,whiteF,'.');
                }
            }
        }
    }
    void move(float time)
    {
        x -= 40 * time;
        
        if(x<0)
        {
            c=rand()%3;
            x=s_width;
        }
    }
};