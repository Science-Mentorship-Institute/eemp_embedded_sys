# Wokwi setup
- Setup Hosted Wokwi Development

    0. Register for an account at https://wokwi.com, then click the "Sign Up" button in the top right.

    1. After registering, click your profile picture in the top right and go to "My Projects" (https://wokwi.com/dashboard/projects).

    2. Create a new project by clicking the "New Project" button.
    ![README Image 1](assets/image/markdown/labsetupimages/wokwisetup_1.png)

    3. In this example, we use an ESP32-C3. Find the ESP32-C3 microcontroller under ESP32. *Please note: the microcontroller may change throughout the lab.*
![README Image 2](assets/image/markdown/labsetupimages/wokwisetup_2.png)

    4. After selecting the microcontroller, select the "Arduino" beginner template.
    -  You should now see a development environment with files like sketch.ino and diagram.json, plus a simulation environment with the ESP32-C3-MINI-1.
        - If you can't see any components, you may have zoomed in or out too far.
![README Image 3](assets/image/markdown/labsetupimages/wokwisetup_3.png)
![README Image 4](assets/image/markdown/labsetupimages/wokwisetup_4.png)

    5. For the labs, you'll copy the diagram.json code from here and paste it into VSCode in your Codespace.
![README Image 5](assets/image/markdown/labsetupimages/wokwisetup_5.png)


# VSCode Wokwi


1. Download the GitHub repo. You'll need a github.com account first. Go to https://github.com/Science-Mentorship-Institute/eemp_embedded_sys
  -> Click on "Use this template"
  -> "Open in codespaces"
![VSCode Wokwi Image 1](assets/image/markdown/labsetupimages/wokwivscode_1.png)

2. **Codespace initialization**: After pressing "Open in a codespace", your Codespace should look similar to the picture below. Please wait patiently while it loads all the VSCode extensions.
![VSCode Wokwi Image 2](assets/image/markdown/labsetupimages/wokwivscode_2.png)
![VSCode Wokwi Image 3](assets/image/markdown/labsetupimages/wokwivscode_3.png)

3. A popup will tell you to restart the Codespace. Do this by refreshing the page.
![VSCode Wokwi Image 4](assets/image/markdown/labsetupimages/wokwivscode_4.png)

4. Setting up the Wokwi CLI token
- Copy the .example.env file to create a .env file in the same directory. You may need to enable clipboard access.
![VSCode Wokwi Image 5](assets/image/markdown/labsetupimages/wokwivscode_5.png)
- Go to the [Wokwi CI token page](https://wokwi.com/dashboard/ci) and click "Create A New Token".
![VSCode Wokwi Image 6](assets/image/markdown/labsetupimages/wokwivscode_6.png)
- Then copy that token.
- Find the .example.env file in the root directory, duplicate it, and rename the copy to .env. Then replace REPLACE in `WOKWI_CLI_TOKEN=REPLACE` with your token.
- Alternatively, in the terminal run `export WOKWI_CLI_TOKEN=<your token>` (replacing `<your token>` with the token you copied).
![VSCode Wokwi Image 7](assets/image/markdown/labsetupimages/wokwivscode_7.png)

5. Activate the Wokwi Simulator Extension
To get Wokwi access in VSCode, you need to add a Wokwi license. Find the Wokwi Simulator extension in the left sidebar of your Codespace's VSCode; it will direct you to a link where you can request a license.
- Click on "Request a New Wokwi License", which will direct you to Wokwi's website, or you can go to https://wokwi.com/dashboard/ci
![VSCode Wokwi Image 8](assets/image/markdown/labsetupimages/wokwivscode_8.png)
- Click on "Get Your License" and copy the license
- In the Wokwi simulator extension, click "Enter License Key" and enter the license key
![VSCode Wokwi Image 9](assets/image/markdown/labsetupimages/wokwivscode_9.png)

## Navigating the lab

### Notes
- Lab 1 and Lab 2 use the Arduino C language instead of regular C or MicroPython.
- Lab completion: students are assigned a multiple-choice quiz.

6. To preview the notes, right-click the markdown file (.md) and select "Open Preview". For example, see the picture below.
![VSCode Wokwi Image 10](assets/image/markdown/labsetupimages/wokwivscode_10.png)

7. sketch.ino is where you place the lab code. You'll need to fill in the blanks.
![VSCode Wokwi Image 11](assets/image/markdown/labsetupimages/wokwivscode_11.png)

8. diagram.json is where you place the lab's schematic. Each lab's `diagram.json` starts almost empty (it contains only the bare ESP32-C3 board). You build the circuit on wokwi.com following the pin tables in the lab notes, then copy that diagram.json and paste it here, replacing the contents. The simulator and `make test-all` will not work until you do this.
![VSCode Wokwi Image 12](assets/image/markdown/labsetupimages/wokwivscode_12.png)
- To edit the raw schematic JSON, right-click diagram.json, choose "Open with...", and select "Text Editor".
![VSCode Wokwi Image 13](assets/image/markdown/labsetupimages/wokwivscode_13.png)
- To open it as a Wokwi simulator, select "Wokwi Diagram Editor".
- The Wokwi simulator requires the Wokwi license — see the VSCode Wokwi section for more information.

## Running the Unit Tests
- Note: the unit tests are there to help you answer the quiz questions. They don't need to pass in order for the assignment to be graded as complete.
- This requires the Wokwi CLI to be set up. For more information, see the VSCode Wokwi section.

9. In the Codespace's VSCode terminal:
- Go to the lab directory with `cd lab1`
- To go back up one directory, use `cd ..`
- Run `make test-all`
- Note: If the wiring_tests.yaml is failing but the regular tests are passing, ignore the wiring tests.
![VSCode Wokwi Image 14](assets/image/markdown/labsetupimages/wokwivscode_14.png)

10. The unit tests pass when you see something similar to below.
![VSCode Wokwi Image 15](assets/image/markdown/labsetupimages/wokwivscode_15.png)
