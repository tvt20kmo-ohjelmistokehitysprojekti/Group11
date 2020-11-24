<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';

/**
 * This is an example of a RestApi based on PHP and CodeIgniter 3.
 * 
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @author          Pekka Alaluukas (edited the version made by Phil Sturgeon & Chris Kacerguis)
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */
class Card extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Card_model');
    }

    public function index_get()
    {
        // book from a data store e.g. database  

        $id = $this->get('id');

        // If the id parameter doesn't exist return all books
        if ($id === NULL)
        {
            $Card=$this->Card_model->get_Card(NULL);
            // Check if the book data store contains book (in case the database result returns NULL)
            if ($Card)
            {
                // Set the response and exit
                $this->response($Card, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No book were found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

         // Find and return a single record for a particular book.
        else {
            // Validate the id.
            if ($id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the book from the database, using the id as key for retrieval.
            $Card=$this->Card_model->get_Card($id);
            if (!empty($Card))
            {
                $this->set_response($Card, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'book could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

    }

    public function index_post()
    {
        $clear_pinCode=$this->post('pinCode');
        $encrypted_pin=password_hash($clear_pinCode, PASSWORD_DEFAULT);
        $add_data=array(
          'idcard'=>$this->post('idcard'),  
          'owner'=>$this->post('owner'),
          'pinCode'=>$encrypted_pin
        );
        $insert_id=$this->Card_model->add_Card($add_data);
        if($insert_id)
        {
            $message = [
                'idcard'=>$this->post('idcard'),
                'owner'=>$this->post('owner'),
                'pinCode'=>$this->post('pinCode'),
                'message' => 'Added a resource'
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
            $message = [
                'idcard'=>$this->post('idcard'),
                'owner'=>$this->post('owner'),
                'pinCode'=>$this->post('pinCode'),
                'message' => 'Added a resource'
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED);
        }

    }
    public function index_put()
    {
        // Update the book
        $id=$this->get('id');
        $update_data=array(
          'owner'=>$this->post('owner'),
          'pinCode'=>$this->post('pinCode')
        );
        $result=$this->Card_model->update_Card($id, $update_data);

        if($result)
        {
            $message = [
                'idcard' => $id,
                'owner'=>$this->post('owner'),
                'pinCode'=>$this->post('pinCode'),
                'message' => 'Updates a resource'
            ];

            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else 
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not update data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }

    public function index_delete()
    {
        $id = $this->get('id');

        // Validate the id.
        if ($id <= 0)
        {
            // Set the response and exit
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
        }
        $result=$this->Card_model->delete_Card($id);
        if ($result)
        {
          $message = [
              'idcard' => $id,
              'message' => 'Deleted the resource'
          ];
          $this->set_response($message, REST_Controller::HTTP_OK);
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not delete data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }



}