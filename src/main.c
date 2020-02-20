//#include <gtk/gtk.h>
#include "screenshot.c"

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;
    //GtkBuilder      *builder;
    //GtkWidget       *window;

    //gtk_init(&argc, &argv);

    //builder = gtk_builder_new();

    //GError *err = NULL;

    //if (0 == gtk_builder_add_from_file (builder, "src/glade/root.glade", &err)) {
    //    /* Print out the error. You can use GLib's message logging */
    //    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
    //    /* Your error handling code goes here */
    //}
    take_screenshot("/tmp/out.png", 1);

    //window = GTK_WIDGET(gtk_builder_get_object(builder, "root"));
    //gtk_builder_connect_signals(builder, NULL);
    //g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK (gtk_main_quit), NULL);

    //g_object_unref(builder);

    //gtk_widget_show(window);
    //gtk_main();

    return 0;
}
