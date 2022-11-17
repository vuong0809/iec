oid reportCallbackFunction(void *parameter, ClientReport report)
{
    MmsValue *dataSetValues = ClientReport_getDataSetValues(report);

    printf("received report for %s\n", ClientReport_getRcbReference(report));

    int i;
    for (i = 0; i < 4; i++)
    {
        ReasonForInclusion reason = ClientReport_getReasonForInclusion(report, i);

        if (reason != IEC61850_REASON_NOT_INCLUDED)
        {
            printf("  GGIO1.SPCSO%i.stVal: %i (included for reason %i)\n", i,
                   MmsValue_getBoolean(MmsValue_getElement(dataSetValues, i)), reason);
        }
    }
}