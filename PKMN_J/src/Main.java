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
        FileInputStream fis = new FileInputStream(file);
        InputStreamReader isr = new InputStreamReader(fis);
        BufferedReader br = new BufferedReader(isr);
        //String line = br.readLine();
        FileWriter fr = new FileWriter(file, true);
        BufferedWriter bw = new BufferedWriter(fr);
        PrintWriter pr = new PrintWriter(bw);



        System.out.println("Hello! Welcome to the file reader and writer.\n");
        Scanner userInput = new Scanner(System.in);
        System.out.println("Which line of the text file would you like to read?");
        int lineX = userInput.nextInt();
        String lineResult = readLineX(lineX, file);
        System.out.println("\nLine "+ lineX +" reads:\n"+ lineResult + "\n");
        System.out.println("Would you like to edit this line?\n");
        String yORn = new String();
        //yORn = userInput.nextLine();
        yORn = "y";

        if( (yORn.equalsIgnoreCase("yes")) || (yORn.equalsIgnoreCase("y"))){
            File tempFile = new File("PKMN_J/JText/tempFile.txt");
            /*BufferedReader reader = new BufferedReader(new FileReader(file));
            BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

            String currentLine = lineResult;
            String lineToRemove;
            while ((currentLine = reader.readLine()) != null) {
                String trimmedLine = currentLine.trim();
                lineToRemove = lineResult;
                if (trimmedLine.equals(lineToRemove)) continue;
               // writer.write(currentLine +  pr.write("replacement"));
            }
            writer.close(); 
            reader.close(); 
            boolean successful = tempFile.renameTo(file);*/
            System.out.println("in yes");
            Scanner sc = new Scanner(file);
            StringBuffer buffer = new StringBuffer();
            while (sc.hasNextLine()) {
                buffer.append(sc.nextLine()+System.lineSeparator());
             }
             String fileContents = buffer.toString();
            
            String newLine = userInput.nextLine();
            fileContents = fileContents.replaceAll(lineResult, newLine);
            FileWriter writer = new FileWriter(file);
            writer.append(fileContents);
            writer.flush();




        }
        else if( (yORn.equalsIgnoreCase("no")) || (yORn.equalsIgnoreCase("n")) ){
            System.out.println("\nLine "+ lineX +" reads:\n"+ lineResult + "\n");
        }
        /*else{
            System.out.println("Not a valid response");
        }*/
        userInput.close();
    }

    public static String readLineX(int lineX, File file) throws IOException{
        String redLine = Files.readAllLines(Paths.get(file.getAbsolutePath())).get(lineX - 1); /*Read specific lines */
        return redLine;
    }
}

