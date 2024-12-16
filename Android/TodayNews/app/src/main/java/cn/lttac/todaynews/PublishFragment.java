package cn.lttac.todaynews;
import android.content.ContentValues;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import androidx.fragment.app.Fragment;

public class PublishFragment extends Fragment {

    private DatabaseHelper dbHelper;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.addnews, container, false);
        String username = GlobalData.getInstance().getUsername();
        dbHelper = new DatabaseHelper(getActivity());
        EditText titleEditText = rootView.findViewById(R.id.edit_title);
        EditText contentEditText = rootView.findViewById(R.id.edit_content);
        Button publishButton = rootView.findViewById(R.id.publish_button);

        publishButton.setOnClickListener(v -> {
            String title = titleEditText.getText().toString();
            String content = contentEditText.getText().toString();
            publishArticle(username,title, content);
        });

        return rootView;
    }

    private void publishArticle(String username,String title, String content) {
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put("username",username);
        values.put("title", title);
        values.put("content", content);
        db.insert("articles", null, values);
        dbHelper.logAllData();
    }

}
