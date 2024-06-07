import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
    
    public static void main(String[] args) throws IOException{
        File file = new File("PKMN_J/readFrom.txt");
        
        System.out.println("Hello! Welcome to the file reader and writer.\n");
        Scanner userInput = new Scanner(System.in);
        System.out.println("Which line of the text file would you like to read?");
        int lineX = userInput.nextInt();
        String lineResult = readLineX(lineX, file);
        System.out.println("\nLine "+ lineX +" reads:\n"+ lineResult);
    }

    public static String readLineX(int lineX, File file) throws IOException{
        String redLine = Files.readAllLines(Paths.get(file.getAbsolutePath())).get(lineX - 1); /*Read specific lines */
        return redLine;
    }
}

