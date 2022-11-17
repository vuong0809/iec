
#include "iec61850_server.h"
#include "hal_thread.h"
// #include <iec61850_server.h>
// #include <hal_thread.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#include "static_model.h"



static int running = 0;

void
sigint_handler(int signalId)
{
	running = 0;
}

int
main(int argc, char** argv)
{
    int tcpPort = 102;

    if (argc > 1) {
        tcpPort = atoi(argv[1]);
    }

    IedServer iedServer = IedServer_create(&iedModel);

    /* set initial measurement and status values from process */

    /* MMS server will be instructed to start listening to client connections. */
    // IedServer_start(iedServer, tcpPort);

    // if (!IedServer_isRunning(iedServer)) {
    //     printf("Starting server failed! Exit.\n");
    //     IedServer_destroy(iedServer);
    //     exit(-1);
    // }

    // running = 1;

    // signal(SIGINT, sigint_handler);

    // while (running) {
    //     Thread_sleep(1);
    // }

    // /* stop MMS server - close TCP server socket and all client sockets */
    // IedServer_stop(iedServer);

    // /* Cleanup - free all resources */
    // IedServer_destroy(iedServer);

    return 0;
} /* main() */
