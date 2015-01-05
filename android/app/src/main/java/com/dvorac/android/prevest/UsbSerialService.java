package com.dvorac.android.prevest;

import android.app.Service;
import android.content.Intent;
import android.os.Binder;
import android.os.IBinder;

public class UsbSerialService extends Service {
    // logcat tag
    public static final String TAG = UsbSerialService.class.getSimpleName();

    private final IBinder mBinder = new UsbSerialServiceBinder();

    public UsbSerialService() {

    }

    @Override
    public IBinder onBind(Intent intent) {
        return mBinder;
    }

    /**
     * Class used for the client Binder.  Because we know this service always
     * runs in the same process as its clients, we don't need to deal with IPC.
     */
    public class UsbSerialServiceBinder extends Binder {
        UsbSerialService getService() {
            // Return this instance of LocalService so clients can call public methods
            return UsbSerialService.this;
        }
    }
}
