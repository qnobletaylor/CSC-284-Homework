### Inventory Management

This program will ask a user to input a file name associated with a .json file representing a shop inventory.
The parsing is done by a template class called InventoryProcessor which can take custom types of inventory items.  
The class itself relies on the fact that any type being passed to the template class must implement certain 
 functions from the nlohmann/json library.

To run the program simply open the solution file (.sln) and click the "play" button or use keybinds ctrl+F5. Then a 
console window will appear and prompt for input. It's important to note that when prompted for a file name, entering 
"myFile.json" will look for a file within the project directory, however you can also input an absolute path to a file.

---

To run, simply open the solution file ``~./HW3/InventoryManagementPt2.sln`` with Visual Studio 2022 and hit ``ctrl + 
F5`` on your keyboard.