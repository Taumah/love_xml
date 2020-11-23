#include "../include/main.h"

//<to>[[:ascii:]]*<\/to>[\n\ \r]*<from>[[:ascii:]]*<\/from>
// regex example to check following elements

doctypeDef dtd; 

extern size_t gap;

int main(int argc, char* argv[]){
    
    (void)argc ; (void)argv;
    initDtd();

    char* fileDTD = "test/dtds/test.dtd";
    // char* fileXML = "test/XML/test.xml";



    readDTD(fileDTD);
    
    // // printDtd();
    
    // char* xmlBuffer = NULL;
    // int readXmlErrors = readXML(fileXML , &xmlBuffer);

    // if(readXmlErrors != EXIT_FAILURE){
    //     if(checkXML(xmlBuffer)){
    //         printf("\nxml valide");
    //     }else
    //     {
    //         printf("\nxml invalidé");
    //     }
        
    // }
    
    // free(xmlBuffer);

    // // menu();

    int test = regexChildren("note" , "<?xml version=\"1.0\" encoding=\"UTF-8 but also something else\" ?>\
<note NAME=\"test\" CHAN=\"test2\" >\
  <to>Tove</to>\
  <from>Jani</from>\
  <heading>Reminder</heading>\
  <body>Don\'t forget me this weekend!</body>\
</note>" );

    printf("\n%d" , test);

    freeDtd();

    return 0;

}

















// #include <gtk/gtk.h>

// int main (int   argc, char *argv[])
// {
//   GtkBuilder *builder;
// //   GObject *window;
// //   GObject *button;
//   GError *error = NULL;

//   gtk_init (&argc, &argv);

//   /* Construct a GtkBuilder instance and load our UI description */
//   builder = gtk_builder_new ();
//   if (gtk_builder_add_from_file (builder, "core/glade/menu.glade", &error) == 0)
//     {
//       g_printerr ("Error loading file: %s\n", error->message);
//       g_clear_error (&error);
//       return 1;
//     }

//   /* Connect signal handlers to the constructed widgets. */
// //   window = gtk_builder_get_object (builder, "window");
// //   g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

// //   button = gtk_builder_get_object (builder, "button1");
// //   g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

// //   button = gtk_builder_get_object (builder, "button2");
// //   g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

// //   button = gtk_builder_get_object (builder, "quit");
// //   g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

//   gtk_main ();

//   return 0;
// }