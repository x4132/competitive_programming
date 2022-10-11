import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class S3Jeff {
    public static void main(String[] args) throws IOException {
        try{
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            
            Integer array[][] = new Integer[3][3];
            for (int i=0; i<3; i++)
            {
                String[] strs = in.readLine().trim().split(" ");
                for(int j=0; j<3; ++j)
                {
                    if (strs[j].equalsIgnoreCase("X"))
                    {
                        array[i][j] = null;
                    }
                    else
                    {
                        array[i][j] = Integer.parseInt(strs[j]);
                    }
                }
            }
            
            solveSimple(array);

            Integer copy[][] = new Integer[3][3];
            copy(array, copy);
            
            int start = 0;
            while (!isSolved(array))
            {
                copy(copy, array);
                
                while(fillOneZero(array, start))
                {
                    solveSimple(array);
                }
                
                start ++;
            }

            printResult(array);
        }
        finally
        {
        }
    }

    public static void copy(Integer from[][], Integer to[][])
    {
        for (int i=0; i<3; i++)
        {
            for(int j=0; j<3; ++j)
            {
                to[i][j] = from[i][j];
            }
        }        
    }
    
    public static boolean isSolved(Integer array[][])
    {
        for (int i=0; i<3; i++)
        {
            if (array[i][0] == null || array[i][1] == null || array[i][2]== null)
                return false;
            
            if(array[i][2] + array[i][0] != 2 * array[i][1]) 
            {
                return false;
            }
        }        
        for (int i=0; i<3; i++)
        {
            if(array[2][i] + array[0][i] != 2 * array[1][i]) 
            {
                return false;
            }
        }        

        return true;
    }
    
    public static boolean fillOneZero(Integer array[][], int filler)
    {
        for (int i=0; i<3; i++)
        {
            for(int j=0; j<3; ++j)
            {
                if (array[i][j] == null)
                {
                    
                    array[i][j] = filler;
                    return true;
                }
            }
        }        
        
        return false;
    }
    
    public static boolean solveSimple(Integer array[][])
    {
        boolean solved = false;
        
        //Check all rows
        for (int i=0; i<3; i++)
        {
            if (array[i][0] == null && array[i][1] != null && array[i][2] != null)
            {
                array[i][0] = 2*array[i][1]-array[i][2];
                solved = true;
            }
            else if (array[i][0] != null && array[i][1] == null && array[i][2] != null)
            {
                array[i][1] = (array[i][0]+array[i][2])/2;
                solved = true;
            }
            else if (array[i][0] != null && array[i][1] != null && array[i][2] == null)
            {
                array[i][2] = 2*array[i][1]-array[i][0];
                solved = true;
            }
        }        

        //Check all columns
        for (int j=0; j<3; j++)
        {
            if (array[0][j] == null && array[1][j] != null && array[2][j] != null)
            {
                array[0][j] = 2*array[1][j]-array[2][j];
                solved = true;
            }
            else if (array[0][j] != null && array[1][j] == null && array[2][j] != null)
            {
                array[1][j] = (array[0][j]+array[2][j])/2;
                solved = true;
            }
            else if (array[0][j] != null && array[1][j] != null && array[2][j] == null)
            {
                array[2][j] = 2*array[1][j]-array[0][j];
                solved = true;
            }
        }
        
        if(solved)
        {
            return solveSimple(array);
        }
        else
        {
            return false;
        }
    }
    
    public static void printResult(Integer array[][])
    {
        for (int i=0; i<3; i++)
        {
            for(int j=0; j<3; ++j)
            {
                System.out.print(array[i][j]);
                System.out.print(" ");
            }
            System.out.print("\n");
        }
    } 
}