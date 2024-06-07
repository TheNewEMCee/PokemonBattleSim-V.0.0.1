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
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
    
    public static void main(String[] args) throws IOException{
        File file = new File("PKMN_J/JText/readFrom.txt");



        System.out.println("Hello! Welcome to the file reader and writer.\n");
        Scanner userInput = new Scanner(System.in);
        System.out.println("Which line of the text file would you like to read?");
        int lineX = userInput.nextInt();
        String lineResult = readLineX(lineX, file);
        System.out.println("\nLine "+ lineX +" reads:\n"+ lineResult + "\n");
        System.out.println("Would you like to delete this line?\n");
        String yORn = userInput.nextLine();
        yORn = userInput.nextLine();

        if( (yORn.equalsIgnoreCase("yes")) || (yORn.equalsIgnoreCase("y"))){
            
            File tempFile = new File("PKMN_J/JText/tempFile.txt");
            BufferedReader reader = new BufferedReader(new FileReader(file));
            BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

            String currentLine = lineResult;
            String lineToRemove;
            while ((currentLine = reader.readLine()) != null) {
                String trimmedLine = currentLine.trim();
                lineToRemove = lineResult;
                if (trimmedLine.equals(lineToRemove)) continue;
                writer.write(currentLine +  System.getProperty("line.separator"));
            }
            writer.close(); 
            reader.close(); 
            boolean successful = tempFile.renameTo(file);
            System.out.println("Line deleted");
        
        }
        else if( (yORn.equalsIgnoreCase("no")) || (yORn.equalsIgnoreCase("n")) ){
            System.out.println("The line has not been deleted");
        }
        else{
            System.out.println("Not a valid response");
        }
        
    
        System.out.println("Would you like to add a line?\n");
        String yORn2 = userInput.nextLine();

        if((yORn2.equalsIgnoreCase("yes")) || (yORn2.equalsIgnoreCase("y"))){
            System.out.println("What would you like to add?");
            String toAdd = userInput.nextLine();
                FileWriter fr = new FileWriter(file, true);
                BufferedWriter bw = new BufferedWriter(fr);
                PrintWriter pr = new PrintWriter(bw);
                pr.write(toAdd);
                pr.close();
                bw.close();
                fr.close();
            System.out.println(toAdd + " added to the file. ");
        }
        else if((yORn2.equalsIgnoreCase("yes")) || (yORn2.equalsIgnoreCase("y"))){
            System.out.println("Nothing has been added to the file.");
        }
        else{
            System.out.println("Not a valid response");
        }
        
        System.out.println("The file reads:\n");
        printFile(file);

    }

    public static String readLineX(int lineX, File file) throws IOException{
        String redLine = Files.readAllLines(Paths.get(file.getAbsolutePath())).get(lineX - 1); /*Read specific lines */
        return redLine;
    }
    public static void printFile(File file)throws IOException{
        Scanner myReader = new Scanner(file);
        while (myReader.hasNextLine()) {
        String data = myReader.nextLine();
        System.out.println(data);
      }
    }
}

