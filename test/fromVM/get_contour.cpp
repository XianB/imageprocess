#include "plate.h"
/*����:�ҳ�ͼ���е����о�������
 ����:Ԥ������ͼ��, ���ɾ������ݽṹ��List��,CvMemStorage����, contours
 ���:������CvRect���;��ε�List��

 */

void get_contour_rect(IplImage * src_img, List  rects, CvMemStorage * storage, CvSeq * contours)
{
	IplImage * temp_img = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_8U, 1);
	temp_img = cvCloneImage(src_img);
	
	/*�ҵ���������,����������storage��*/
	/*ע��:�����޸�Ϊ��ֻ���������*/
	cvFindContours(temp_img, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_RETR_EXTERNAL | CV_CHAIN_APPROX_SIMPLE);

	/*��storage��ɸѡ����������*/
	while (contours != NULL) {
		push_back(rects, cvBoundingRect(contours, 0));
		rects = rects->next;
		contours = contours->h_next;
	}
}

/*����֮ǰ�ҵ������о�����״��λ��*/
void draw_contour_rect(IplImage * src_img, List rects)
{
	if (rects == NULL) {
		fprintf(stderr, "rects is NULL! in draw_contour_rect function.\n");
		return;
//		exit(-1);
	}

	IplImage * temp_img = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_8U, 1);
//	cvNamedWindow("img_with_rect");

	temp_img = cvCloneImage(src_img);
	if (temp_img == NULL) {
		fprintf(stderr, "temp_img is NULL!\n");
		exit(-1);
	}
	while (rects != NULL) {
		cvRectangle(temp_img, cvPoint(rects->item.x, rects->item.y), cvPoint(rects->item.x + rects->item.width, rects->item.y + rects->item.height), CV_RGB(0xbF, 0xbd, 0xab), 1, 8, 0);
		rects = rects->next;
	}
	//cvShowImage("img_with_rect", temp_img);
	//cvWaitKey(0);
}


/*��ӡ�����ε����*/
void print_area_of_rect(CvRect rect)
{
	//printf("the area of this rect is %d\n", rect.width * rect.height);
}

